import mongoose from "mongoose";
import logger from "../lib/winston/index.js";

// eslint-disable-next-line no-unused-vars
const errorHandler = (err, req, res, next) => {
  if (err instanceof SyntaxError) return handleJSONParseError();

  if (err instanceof mongoose.Error.ValidationError || err.code === 11000) return handleMongooseError(err, req, res);

  console.error(err);

  logger.error(err.stack || err.message);

  return res.status(500).json({
    error: true,
    message: "Internal Server Error",
  });
};

export default errorHandler;

const handleJSONParseError = (err, req, res) => {
  res.status(400).json({ error: true, message: "Invalid data format, please send json format" });
};

const handleMongooseError = (err, req, res) => {
  if (err instanceof mongoose.Error.ValidationError) {
    res.status(400).json({
      error: true,
      message: "Validation error, please provide valid data",
      formValidation: Object.values(err.errors).map((error) => ({
        field: error.path,
        errors: [error.message],
      })),
    });
  } else if (err.code === 11000) {
    return res.status(400).json({
      error: true,
      message: "Duplicate key error, please use a unique value",
      formValidation: Object.keys(err.keyValue).map((field) => ({
        field,
        errors: [`${field} must be unique`],
      })),
    });
  }

  console.error(err);
  logger.error(err.stack || err.message);

  return res.status(500).json({ error: true, message: "Internal Server Error" });
};
