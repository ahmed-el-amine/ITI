import { z } from "zod";

export const useZod = (schema) => (req, res, next) => {
  try {
    schema.parse(req.body);
    next();
  } catch (error) {
    if (error instanceof z.ZodError) {
      return res.status(400).json({
        error: true,
        message: "Validation error, please provide valid data",
        formValidation: error.errors.map((err) => ({
          field: err.path.join("."),
          errors: [err.message],
        })),
      });
    }
    return res.status(500).json({ error: true, message: "Internal Server Error" });
  }
};

export default useZod;
