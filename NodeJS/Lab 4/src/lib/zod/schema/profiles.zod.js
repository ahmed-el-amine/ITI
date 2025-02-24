import { z } from "zod";

export const createProfilesValidationSchema = z
  .object({
    title: z.string().min(1, "Title is required").max(50, "Title must be at most 50 characters"),
    description: z.string().min(1, "Description is required").max(1000, "Description must be at most 1000 characters"),
    yearsOfExperience: z.coerce.number().int().nonnegative().default(0),
    department: z.string().min(1, "Department is required"),
    phoneNumber: z.string().min(1, "Phone number is required"),
    email: z.string().email("Invalid email format"),
  })
  .strip();
