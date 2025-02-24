import { z } from "zod";

const baseLeavesSchema = z
  .object({
    type: z.enum(["annual", "casual", "sick"], {
      message: "Type must be one of: annual, casual, or sick",
    }),
    duration: z.coerce.number().int().positive("Duration must be a positive number"),
    status: z.enum(["inprogress", "cancelled", "ended"]).default("inprogress"),
  })
  .strip();

export const createLeavesValidationSchema = baseLeavesSchema;

export const updateLeavesValidationSchema = baseLeavesSchema;

export const searchLeavesValidationSchema = baseLeavesSchema.partial();
