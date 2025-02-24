import express from "express";
import useZod from "../middleware/useZod.js";
import { addEmployeeSchema, updateEmployeeSchema } from "../lib/zod/employessZodSchema.js";
import { addEmployee, deleteEmployeeById, getAllData, getEmployeeById, updateEmployeeById } from "../controllers/employee.js";

const router = express.Router();

router.get("/", async (req, res) => {
  // get all query
  const { name, salary, level, yearsOfExperience } = req.query;

  const data = getAllData();

  data.employees = data.employees.filter((emp) => {
    if (name) return emp.name.toLowerCase().includes(name.toLowerCase());
    if (salary) return emp.salary == salary;
    if (level) return emp.level == level;
    if (yearsOfExperience) return emp.yearsOfExperience == yearsOfExperience;
    return true;
  });

  if (data.employees.length == 0) {
    return res.status(404).json({ error: true, message: "No employees found" });
  }

  res.render("index", { employees: data.employees });
});

router.get("/:id", async (req, res) => {
  const data = getEmployeeById(req.params.id);
  if (!data) return res.status(404).json({ error: true, message: "Employee not found" });

  res.json(data);
});

router.post("/", useZod(addEmployeeSchema), async (req, res) => {
  const data = addEmployee(req.body);
  res.status(201).json({
    message: "Employee added successfully",
    employee: data,
  });
});

router.delete("/:id", async (req, res) => {
  const deletedEmp = deleteEmployeeById(req.params.id);

  if (deletedEmp === null) {
    return res.status(404).json({ error: true, message: "Employee not found" });
  }

  res.json({
    message: "Employee deleted successfully",
    employee: deletedEmp,
  });
});

router.patch("/:id", useZod(updateEmployeeSchema), async (req, res) => {
  const employee = updateEmployeeById(req.params.id, req.body);

  if (employee === null) {
    return res.status(404).json({ error: true, message: "Employee not found" });
  }

  res.json({
    employee: {
      message: "Employee updated successfully",
      employee,
    },
  });
});

export default router;
