import express from "express";
import employess from "./routes/employees.js";
import path from "path";

// create server
const app = express();

// serve static files
app.use(express.static(path.join(process.cwd(), "public")));

// parse json
app.use(express.json());

// set view engine
app.set("view engine", "pug");
app.set("views", path.join(process.cwd(), "src/views"));

// routes
app.use("/employees", employess);

// start server
app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
