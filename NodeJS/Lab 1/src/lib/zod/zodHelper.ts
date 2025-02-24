import { ZodError } from "zod";

export const showErrors = (error: ZodError) => {
  return error.errors.map(({ path, message }) => `${path.join(".")}: ${message}`).join("\n");
};
