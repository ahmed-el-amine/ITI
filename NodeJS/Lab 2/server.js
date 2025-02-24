import path from "path";
import star from "./src/lib/star/index.js";
import fs from "fs";

const app = star();

app.server.listen(3000, () => {
  console.log("Server running at http://localhost:3000/");
});

// static files
app.staticDir(path.join(process.cwd(), "public"));

// Q1

app.get("/", async (req, res) => {
  const stream = fs.createReadStream("./database/db.json");

  let employess = "";
  stream.on("data", (data) => {
    employess += data.toString("utf8");
  });

  stream.on("end", () => {
    employess = JSON.parse(employess);
    res.writeHead(200, { "Content-Type": "application/json" });
    res.write(
      JSON.stringify(
        employess.employees.map((x) => {
          delete x.id;
          return { ...x };
        })
      )
    );
    res.end();
  });
});

// Q2

app.get("/astronomy", async (req, res) => {
  res.writeHead(404, { "Content-Type": "text/html" });
  res.write(`
    <style>
    * { padding: 0; margin: 0 }
    </style>
    <img width="100%" height="100%" src='/200505225212-04-fossils-and-climate-change-museum.jpg' />
    <p>
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime mollitia,
molestiae quas vel sint commodi repudiandae consequuntur voluptatum laborum
numquam blanditiis harum quisquam eius sed odit fugiat iusto fuga praesentium
optio, eaque rerum! Provident similique accusantium nemo autem. Veritatis
obcaecati tenetur iure eius earum ut molestias architecto voluptate aliquam
    </p>
    `);
  res.end();
});

// Q 3

app.get("/serbal", async (req, res) => {
  res.writeHead(404, { "Content-Type": "text/html" });
  res.write(`
    <style>
    * { padding: 0; margin: 0 }
    </style>
    <img width="100%" height="100%" src='/DCnpfBy_d.webp' />
    <p>
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime mollitia,
molestiae quas vel sint commodi repudiandae consequuntur voluptatum laborum
numquam blanditiis harum quisquam eius sed odit fugiat iusto fuga praesentium
optio, eaque rerum! Provident similique accusantium nemo autem. Veritatis
obcaecati tenetur iure eius earum ut molestias architecto voluptate aliquam
    </p>
    `);
  res.end();
});

// Q 4

app.notFound((r, res) => {
  res.writeHead(404, { "Content-Type": "text/html" });
  res.end("404 Not Found. The page you are looking for does not exist.");
});

// Q 5 Bonus

app.get("/astronomy/download", async (req, res) => {
  const fileName = "200505225212-04-fossils-and-climate-change-museum.jpg";
  let filePath = "./public/" + fileName;

  if (!fs.existsSync(filePath)) {
    res.writeHead(404, { "Content-Type": "text/plain" });
    res.end("Image not found");
    return;
  }

  const fileStat = fs.statSync(filePath);

  res.writeHead(200, {
    "Content-Type": "application/octet-stream",
    "Content-Disposition": `attachment; filename="${fileName}"`,
    "Content-Length": `${fileStat.size}`,
  });

  res.end();
});

// Q 6 Bonus

app.post("/employee", async (req, res) => {
  let body = "";

  req.on("data", (chunk) => {
    body += chunk.toString();
  });

  req.on("end", () => {
    try {
      const data = JSON.parse(body); // Parse JSON body
      res.writeHead(200, { "Content-Type": "application/json" });

      // 1- validate the data
      // 2- save this in database file

      res.end(JSON.stringify({ data }));
    } catch (e) {
      console.log(e.message);
      res.writeHead(400, { "Content-Type": "application/json" });
      res.end(JSON.stringify({ error: false, message: "please provide a valid JSON" }));
    }
  });
});
