import mongoose from "mongoose";
import capitalized from "../../utils/capitalized.js";
import bcrypt from "bcrypt";
import jwt from "jsonwebtoken";

const employeesSchema = new mongoose.Schema(
  {
    username: {
      type: String,
      required: true,
      unique: true,
      trim: true,
      min: [8, "Username must be at least 8 characters"],
    },
    firstName: {
      type: String,
      required: true,
      min: [3, "First name must be at most 15 characters"],
      max: [15, "First name must be at most 15 characters"],
      uppercase: true,
      set: (value) => capitalized(value),
    },
    lastName: {
      type: String,
      required: true,
      min: [3, "First name must be at most 15 characters"],
      max: [15, "First name must be at most 15 characters"],
      uppercase: true,
      set: (value) => capitalized(value),
    },
    dateOfBirth: {
      type: Date,
      required: true,
    },
    password: {
      type: String,
      required: true,
      min: [8, "Password must be at least 8 characters"],
    },
    roles: {
      type: [String],
      enum: ["admin", "user"],
      default: ["user"],
    },
  },
  {
    timestamps: true,
    toJSON: { virtuals: true },
    toObject: { virtuals: true },
  }
);

employeesSchema.pre("save", async function (next) {
  if (this.isModified("password")) {
    this.password = await bcrypt.hash(this.password, 10);
  }
  next();
});

employeesSchema.virtual("age").get(function () {
  if (!this.dateOfBirth) return null;
  const diff = Date.now() - this.dateOfBirth.getTime();
  return Math.floor(diff / (1000 * 60 * 60 * 24 * 365.25));
});

employeesSchema.methods.comparePassword = async function (password) {
  const isMatch = await bcrypt.compare(password, this.password);
  return isMatch;
};

employeesSchema.methods.createAuthToken = function () {
  const token = jwt.sign({ id: this._id }, process.env.JWT_SECRET, {
    expiresIn: process.env.JWT_EXPIRATION,
  });

  return token;
};

employeesSchema.methods.toJSON = function () {
  const employee = this.toObject();
  delete employee.password;
  delete employee.__v;
  delete employee.roles;
  return employee;
};

const Employees = mongoose.model("employees", employeesSchema);

export default Employees;
