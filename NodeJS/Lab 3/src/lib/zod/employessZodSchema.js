import { z } from "zod";

export const addEmployeeSchema = z.object({
  name: z.string().min(3, "Name must be at least 3 characters"),
  email: z.string().email("Invalid email address"),
  salary: z.number().min(1000, "Salary must be at least 1000"),
  level: z.enum(["junior", "mid", "senior"]),
  yearsOfExperience: z.number().min(0, "Experience must be a non-negative number"),
});

export const updateEmployeeSchema = z.object({
  name: z.string().min(3, "Name must be at least 3 characters").optional(),
  email: z.string().email("Invalid email address").optional(),
  salary: z.number().min(1000, "Salary must be at least 1000").optional(),
  level: z.enum(["junior", "mid", "senior"]).optional(),
  yearsOfExperience: z.number().min(0, "Experience must be a non-negative number").optional(),
});
