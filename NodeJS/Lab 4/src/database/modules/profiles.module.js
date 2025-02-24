import mongoose from "mongoose";
import { zodValidator } from "../../lib/zod/utils.js";
import { z } from "zod";

const profilesSchema = new mongoose.Schema(
  {
    employeeID: {
      type: mongoose.Schema.Types.ObjectId,
      ref: "employees",
      required: true,
      unique: true,
    },
    title: {
      type: String,
      required: true,
    },
    description: {
      type: String,
      required: true,
    },
    yearsOfExperience: {
      type: Number,
      default: 0,
    },
    department: {
      type: String,
      required: true,
    },
    phoneNumber: {
      type: String,
      required: true,
    },
    email: {
      type: String,
      required: true,
      validate: {
        validator: (value) => {
          return zodValidator(value, z.string().email());
        },
        message: "Invalid email format",
      },
    },
  },
  {
    timestamps: true,
  }
);

const Profiles = mongoose.model("profiles", profilesSchema);

export default Profiles;
