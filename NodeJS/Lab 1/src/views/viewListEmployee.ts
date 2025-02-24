import DB from "../db";
// import { validateIdSchema } from "../lib/zod/shema";
// import { showErrors } from "../lib/zod/zodHelper";
import { ParseArgsReturnProps } from "../utils/args";

const viewListEmployee = async (args: ParseArgsReturnProps) => {
  const id = args.operationData[0];

  const db = DB.getDB();

  // filter list by id if exist
  if (id) {
    const employees = db.getEmployees().filter((e: any) => e.id == id);

    if (employees.length == 0) {
      console.log("there is no employee with this id");
      return;
    }

    showEmployees(employees);

    return;
  }

  // filter list by filters if exist
  if (Object.keys(args.data).length != 0) {
    const employees = db.getEmployees().filter((e: any) => {
      return Object.keys(args.data).every((key) => e[key] == args.data[key]);
    });

    if (employees.length == 0) {
      console.log("there is no employees with this filters");
      return;
    }

    showEmployees(employees);
    return;
  }

  showEmployees(db.getEmployees());
};

export default viewListEmployee;

const showEmployees = (data: { [key: string]: string }[]) => {
  for (const emp of data) {
    console.log(
      `id: ${emp.id} name: ${emp.name} email: ${emp.email} salary: ${emp.salary} level: ${emp.level} yearsOfExperience: ${emp.yearsOfExperience}`
    );
  }
};
