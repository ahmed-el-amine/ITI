import { employeeSchema } from "../lib/zod/shema";
import DB from "../db";
import { showErrors } from "../lib/zod/zodHelper";
import { ParseArgsReturnProps } from "../utils/args";

const viewAddEmployee = async (args: ParseArgsReturnProps) => {
  const result = employeeSchema.safeParse(args.data);

  if (!result.success) {
    console.log(showErrors(result.error));
    return;
  }

  // save to db
  const db = DB.getDB();
  // get last index
  const lastIndex = db.getLastIndex();

  // // update last index
  await db.addEmployee({ ...result.data, id: lastIndex + 1 });

  // update last index
  db.updateLastIndex(lastIndex + 1);

  console.log("Employee added successfully");
};

export default viewAddEmployee;
