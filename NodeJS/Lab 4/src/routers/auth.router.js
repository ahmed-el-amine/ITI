import express from "express";
import useZod from "../middleware/useZod.js";
import { loginEmployeesValidationSchema } from "../lib/zod/schema/employes.zod.js";
import Employees from "../database/modules/employees.module.js";

const router = express.Router();

router.post("/login", useZod(loginEmployeesValidationSchema), async (req, res) => {
  const { username, password } = req.body;
  const employee = await Employees.findOne({ username: username });

  if (!employee) return res.status(401).json({ error: true, message: "username or password is incorrect" });

  const isPasswordMatch = await employee.comparePassword(password);

  if (!isPasswordMatch) return res.status(401).json({ error: true, message: "username or password is incorrect" });

  const token = employee.createAuthToken();

  res.cookie(process.env.JWT_Cookie_Name, token, {
    path: "/",
    secure: true,
    httpOnly: true,
    maxAge: 7 * 24 * 60 * 60 * 1000,
  });

  res.send({
    error: false,
    message: "Login successful",
    data: { token, user: employee },
  });
});

export default router;
