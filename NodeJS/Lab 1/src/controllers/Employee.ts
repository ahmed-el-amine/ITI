import DB from "../db";
import { employeeSchema, employeeUpdateSchema, validateIdSchema } from "../lib/zod/shema";
import { showErrors } from "../lib/zod/zodHelper";
import { ParseArgsReturnProps } from "../utils/args";

interface AddEmployeeProps {
  data: { [key: string]: string };
}

interface EditEmployeeProps {
  id: string;
  data: { [key: string]: string };
}

interface DeleteEmployeeProps {
  id: string;
}
class Employee {
  constructor() {}

  public static async addEmployee(props: AddEmployeeProps) {
    const result = employeeSchema.safeParse(props.data);

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
  }

  public static async listEmployee(args: ParseArgsReturnProps) {
    const id = args.operationData[0];

    const db = DB.getDB();

    // filter list by id if exist
    if (id) {
      const employees = db.getEmployees().filter((e: any) => e.id == id);

      if (employees.length == 0) {
        console.log("there is no employee with this id");
        return;
      }

      this.showEmployees(employees);

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

      this.showEmployees(employees);
      return;
    }

    this.showEmployees(db.getEmployees());
  }

  public static async editEmployee(props: EditEmployeeProps) {
    const id = props.id;

    if (!id) {
      console.log("Id is required");
      return;
    }

    const validationResult = validateIdSchema.safeParse({ id });

    if (!validationResult.success) {
      return console.log(showErrors(validationResult.error));
    }

    const result = employeeUpdateSchema.safeParse(props.data);

    if (!result.success) {
      return console.log(showErrors(result.error));
    }
    const db = DB.getDB();

    const editResult = db.editEmployee(props.data);
    if (editResult) {
      console.log("Employee updated successfully");
    } else {
      console.log("Employee not found");
    }
  }

  public static async deleteEmployee(args: DeleteEmployeeProps) {
    const id = args.id;

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
  }

  private static showEmployees = (data: { [key: string]: string }[]) => {
    for (const emp of data) {
      console.log(
        `id: ${emp.id} name: ${emp.name} email: ${emp.email} salary: ${emp.salary} level: ${emp.level} yearsOfExperience: ${emp.yearsOfExperience}`
      );
    }
  };
}

export default Employee;
