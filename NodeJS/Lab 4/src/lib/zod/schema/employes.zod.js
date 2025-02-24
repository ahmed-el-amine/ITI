import { z } from "zod";

const baseEmployeesSchema = z
  .object({
    username: z.string().trim().min(8, "Username must be at least 8 characters").regex(/^\S+$/, "Username must not contain spaces"),
    firstName: z.string().min(3, "First name must be at least 3 characters").max(15, "First name must be at most 15 characters"),
    lastName: z.string().min(3, "Last name must be at least 3 characters").max(15, "Last name must be at most 15 characters"),
    dateOfBirth: z.coerce.date({ required_error: "Date of birth is required" }),
    password: z.string().min(8, "Password must be at least 8 characters"),
  })
  .strip();

export const createEmployeesValidationSchema = baseEmployeesSchema;

export const updateEmployeesValidationSchema = baseEmployeesSchema
  .partial()
  .refine((data) => Object.keys(data).length > 0, { message: "At least one field must be provided for update", path: [] });

export const loginEmployeesValidationSchema = baseEmployeesSchema.pick({ username: true, password: true });
