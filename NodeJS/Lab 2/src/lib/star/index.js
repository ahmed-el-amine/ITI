import fs, { existsSync } from "fs";
// eslint-disable-next-line no-unused-vars
import http, { IncomingMessage, ServerResponse } from "http";
import path from "path";

const star = () => {
  const routes = {
    get: {},
    post: {},
    delete: {},
    patch: {},
    put: {},
    notFound: (_, res) => {
      res.writeHead(404, { "Content-Type": "text/html" });
      res.end("404 Not Found. The page you are looking for does not exist.");
    },
    any: null,
    static: null,
  };

  let server = http.createServer(async (req, res) => {
    const protocol = req.headers["x-forwarded-proto"] || "http";
    const host = req.headers.host;

    // get path and method
    const { url, method } = req;

    //thanks mohammed amr finding a bug
    const { pathname } = new URL(url, `${protocol}://${host}`);

    const callbackRequest = routes[method.toLowerCase()]?.[pathname];
    // if there is registerd route
    if (callbackRequest) await callbackRequest(req, res);
    // check if required path is file
    else if (routes.static) {
      // check if file exist is this static path
      const filePath = path.join(routes.static, url);
      if (!existsSync(filePath)) return await routes.notFound(req, res);

      // res.writeHead(200, { "Content-Type": "application/octet-stream" });
      fs.createReadStream(filePath).pipe(res);
    }
    // if there is any routes
    else if (routes.any) await routes.any(req, res);
    // if not found page
    else await routes.notFound(req, res);
  });

  /**
   * Registers a GET route
   *
   * @param {string} path - The route path.
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const get = (path, callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.get[path] = callback;
  };

  /**
   * Registers a POST route
   *
   * @param {string} path - The route path.
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const post = (path, callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.post[path] = callback;
  };

  /**
   * Registers a PATCH route
   *
   * @param {string} path - The route path.
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const patch = (path, callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.patch[path] = callback;
  };

  /**
   * Registers a PUT route
   *
   * @param {string} path - The route path.
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const put = (path, callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.put[path] = callback;
  };

  /**
   * Registers a DELETE route
   *
   * @param {string} path - The route path.
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const _delete = (path, callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.delete[path] = callback;
  };

  /**
   * Registers a NotFound route
   *
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const notFound = (callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.notFound = callback;
  };

  /**
   * Registers a ANY route
   *
   * @param {(req: IncomingMessage, res: ServerResponse) => void} callback - The request handler function.
   */
  const any = (callback) => {
    if (typeof callback !== "function") throw Error("router callback requires a function");
    routes.any = callback;
  };

  /**
   * Registers a Static files dir
   *
   * @param {string} path - The route path.
   */
  const staticDir = (path) => (routes.static = path);

  return { server, get, post, patch, put, delete: _delete, any, notFound, staticDir };
};

export default star;
