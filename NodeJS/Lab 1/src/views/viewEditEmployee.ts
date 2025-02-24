import { employeeUpdateSchema, validateIdSchema } from "../lib/zod/shema";
import DB from "../db";
import { showErrors } from "../lib/zod/zodHelper";
import { ParseArgsReturnProps } from "../utils/args";

const viewEditEmployee = async (args: ParseArgsReturnProps) => {
  const id = args.operationData[0];

  if (!id) {
    console.log("Id is required");
    return;
  }

  const validationResult = validateIdSchema.safeParse({ id });

  if (!validationResult.success) {
    return console.log(showErrors(validationResult.error));
  }

  const result = employeeUpdateSchema.safeParse(args.data);

  if (!result.success) {
    return console.log(showErrors(result.error));
  }

  // save to db
  const db = DB.getDB();

  const result2 = db.editEmployee(args.data);
  if (result2) {
    console.log("Employee updated successfully");
  } else {
    console.log("Employee not found");
  }
};

export default viewEditEmployee;
