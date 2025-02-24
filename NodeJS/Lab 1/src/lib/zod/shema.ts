import { z } from "zod";

export const employeeSchema = z.object({
  name: z.string().min(1, "Name is required"),
  email: z.string().email("Invalid email format"),
  salary: z.coerce.number().positive("Salary must be a positive number"),
  level: z.enum(["Jr", "Mid-Level", "Sr", "Lead"]).default("Jr"),
  yearsOfExperience: z.coerce.number().nonnegative().default(0),
});

export const employeeUpdateSchema = z.object({
  name: z.string().min(1, "Name is required").optional(),
  email: z.string().email("Invalid email format").optional(),
  salary: z.coerce.number().positive("Salary must be a positive number").optional(),
  level: z.enum(["Jr", "Mid-Level", "Sr", "Lead"]).default("Jr").optional(),
  yearsOfExperience: z.coerce.number().nonnegative().default(0).optional(),
});

export const validateIdSchema = z.object({
  id: z.coerce.number({ message: "Id must be a number" }).int().min(1, { message: "Id must be greater than 0" }),
});
