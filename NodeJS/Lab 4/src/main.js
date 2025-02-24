import express from "express";
import cors from "cors";
// import mongoSanitize from "express-mongo-sanitize";
import compression from "compression";
import cookieParser from "cookie-parser";
import connectDB from "./database/connection.js";
import router from "./routers/index.js";
import errorHandler from "./middleware/errorHandler.js";
import logger from "./lib/winston/index.js";
const app = express();

const PORT = process.env.PORT || 3000;

app.use(compression());
app.use(
  cors({
    origin: "http://127.0.0.1:1500",
    credentials: true,
  })
);
app.use(express.json());
app.use(cookieParser());
// app.use(mongoSanitize());

app.use("/api/v1", router);

// error handler
app.use(errorHandler);

connectDB()
  .then(() => {
    app.listen(PORT, () => {
      logger.info(`Server Is Up And Running On http://localhost:${PORT}`);
    });
  })
  .catch((err) => {
    logger.error(err);
  });
