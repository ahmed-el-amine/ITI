import DB from "../db";
import { validateIdSchema } from "../lib/zod/shema";
import { showErrors } from "../lib/zod/zodHelper";
import { ParseArgsReturnProps } from "../utils/args";

const viewDeleteEmployee = async (args: ParseArgsReturnProps) => {
  const id = args.operationData[0];

  if (!id) {
    console.log("Id is required");
    return;
  }
  const validationResult = validateIdSchema.safeParse({ id });

  if (!validationResult.success) {
    return console.log(showErrors(validationResult.error));
  }

  const db = DB.getDB();

  const result = db.deleteEmployee(id);

  if (result) {
    console.log(`Employee with id ${id} deleted successfully`);
  } else {
    console.log("Employee not found with this id", id);
  }
};

export default viewDeleteEmployee;
