import { readFileSync, writeFileSync } from "fs";
import path from "path";

const dbPath = path.join(process.cwd(), "database", "db.json");

export const getAllData = () => {
  return JSON.parse(readFileSync(dbPath, "utf8"));
};

export const deleteEmployeeById = (id) => {
  if (!id) return null;
  const data = getAllData();
  const employee = data.employees.find((emp) => emp.id == id);
  if (!employee) return null;
  data.employees = data.employees.filter((emp) => emp.id !== id);
  saveData(data);
  return employee;
};

export const getEmployeeById = (id) => {
  if (!id) return null;
  const data = getAllData();
  const employee = data.employees.find((emp) => emp.id == id);
  return employee;
};

export const addEmployee = (employee) => {
  const data = getAllData();
  const newID = (data.schema.lastIndex += 1);
  data.employees.push({ ...employee, id: newID });
  saveData(data);
  return employee;
};

export const updateEmployeeById = (id, updateData) => {
  if (!id) return null;

  const data = getAllData();
  let employee = data.employees.find((emp) => emp.id == id);

  if (!employee) return null;

  employee = { ...employee, ...updateData, id: employee.id };
  saveData(data);

  return employee;
};

const saveData = (data) => {
  writeFileSync(dbPath, JSON.stringify(data));
};
