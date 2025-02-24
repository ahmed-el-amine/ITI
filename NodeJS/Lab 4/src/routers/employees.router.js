import express from "express";
import Employees from "../database/modules/employees.module.js";
import useZod from "../middleware/useZod.js";
import { createEmployeesValidationSchema, updateEmployeesValidationSchema } from "../lib/zod/schema/employes.zod.js";
import Leaves from "../database/modules/leaves.module.js";
import useAuth from "../middleware/useAuth.js";

const router = express.Router();

router.get("/", useAuth(["user"]), async (req, res) => {
  const employees = await Employees.find().select("firstName lastName age dateOfBirth");
  res.json({
    error: false,
    message: null,
    data: employees,
  });
});

router.post("/", useZod(createEmployeesValidationSchema), async (req, res) => {
  // first check if username already exist
  const isExist = await Employees.findOne({ username: req.body.username });
  if (isExist) return res.status(400).json({ error: true, message: "username already exist" });
  // then create new employee

  const employee = await Employees.create(req.body);

  res.status(201).json({
    error: false,
    message: "Employee created successfully",
    data: employee,
  });
});

router.delete("/", useAuth(["user"]), async (req, res) => {
  const employee = await Employees.findByIdAndDelete(req.userID);

  if (!employee) return res.status(404).json({ error: true, message: "Employee not found" });

  res.json({
    error: false,
    message: "Employee deleted successfully",
    data: employee,
  });
});

router.patch("/", useAuth(["user"]), useZod(updateEmployeesValidationSchema), async (req, res) => {
  const employee = await Employees.findByIdAndUpdate(req.userID, req.body, { new: true });

  if (!employee) return res.status(404).json({ error: true, message: "Employee not found" });

  res.json({
    error: false,
    message: "Employee updated successfully",
    data: employee,
  });
});

router.get("/:id/leaves", useAuth(["user"]), async (req, res) => {
  const leaves = await Leaves.find({ employeeID: req.userID });

  res.json({
    error: false,
    message: null,
    data: leaves,
  });
});

export default router;
