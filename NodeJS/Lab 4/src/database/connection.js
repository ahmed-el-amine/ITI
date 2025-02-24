import mongoose from "mongoose";

const connectDB = () =>
  new Promise((resolve, reject) => {
    const MONGODB_URI = process.env.MONGODB_URI;
    if (!MONGODB_URI) throw new Error("Please define the MONGODB_URI environment variable inside .env.local");

    mongoose
      .connect(MONGODB_URI)
      .then(() => resolve(true))
      .catch((err) => reject(err));
  });

export default connectDB;
