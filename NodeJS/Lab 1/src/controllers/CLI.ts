import prompts from "prompts";
import { employeeSchema, validateIdSchema } from "../lib/zod/shema";
import Employee from "./Employee";
import DB from "../db";

class CLI {
  constructor() {}

  public static async showMainMenu() {
    while (true) {
      const response = await prompts({
        type: "select",
        name: "option",
        message: "Choose an option:",
        choices: [
          { title: "Add", value: "add" },
          { title: "Delete", value: "delete" },
          { title: "List", value: "list" },
          { title: "Update", value: "update" },
          { title: "Exit", value: "exit" },
        ],
      });

      switch (response.option) {
        case "add":
          await this.showAddMenu();
          break;
        case "delete":
          await this.showDeleteMenu();
          break;
        case "list":
          console.log("Not implemented yet");
          break;
        case "update":
          await this.showEditMenu();
          break;
        case "exit":
          console.log("Exiting...");
          return;
      }
    }
  }

  private static async showAddMenu() {
    const response = await prompts([
      {
        type: "text",
        name: "name",
        message: "Enter your name:",
        validate: (value) => (value.trim() ? true : "Name is required"),
      },
      {
        type: "text",
        name: "email",
        message: "Enter your email:",
        validate: (value) => (employeeSchema.shape.email.safeParse(value).success ? true : "Invalid email format"),
      },
      {
        type: "number",
        name: "salary",
        message: "Enter your salary:",
        validate: (value) => (value > 0 ? true : "Salary must be a positive number"),
      },
      {
        type: "select",
        name: "level",
        message: "Select your level:",
        choices: [
          { title: "Jr", value: "Jr" },
          { title: "Mid-Level", value: "Mid-Level" },
          { title: "Sr", value: "Sr" },
          { title: "Lead", value: "Lead" },
        ],
        initial: 0,
      },
      {
        type: "number",
        name: "yearsOfExperience",
        message: "Enter years of experience:",
        initial: 0,
        validate: (value) => (value >= 0 ? true : "Years of experience cannot be negative"),
      },
    ]);

    await Employee.addEmployee({ data: response });
  }

  private static async showDeleteMenu() {
    const response = await prompts([
      {
        type: "text",
        name: "id",
        message: "Enter employee id:",
        validate: (value) => (validateIdSchema.shape.id.safeParse(value).success ? true : "Invalid id format"),
      },
    ]);

    await Employee.deleteEmployee({ id: response.id });
  }

  private static getType = (field: any) => {
    if (field === "salary" || field === "yearsOfExperience") {
      return "number";
    }
    if (field === "level") return "select";
    return "text";
  };

  private static async showEditMenu() {
    const { id } = await prompts({
      type: "text",
      name: "id",
      message: "Enter employee ID:",
      validate: (value) => (validateIdSchema.shape.id.safeParse(value).success ? true : "Invalid id format"),
    });

    const db = DB.getDB();
    const user = db.getEmployees().find((x) => x.id == id);
    delete (user as any).id;

    if (!user) {
      console.log("Employee not found");

      return;
    }

    const { fields } = await prompts({
      type: "multiselect",
      name: "fields",
      message: "Select fields to update:",
      choices: [...Object.keys(user).map((key) => ({ title: key, value: key }))],
      min: 1,
    });

    let updateData: any = {};
    for (const field of fields) {
      const type = this.getType(field);
      const fieldPrompt = await prompts({
        type,
        name: field,
        message: `Enter new value for ${field}:`,
        validate: (value) => {
          const validation = employeeSchema.shape[field as keyof typeof employeeSchema.shape]?.safeParse(value);
          if (!validation) return true;
          return validation?.success ? true : validation?.error?.errors[0]?.message;
        },
        ...(type === "select" && {
          choices: [
            { title: "Jr", value: "Jr" },
            { title: "Mid-Level", value: "Mid-Level" },
            { title: "Sr", value: "Sr" },
            { title: "Lead", value: "Lead" },
          ],
          initial: 0,
        }),
      });

      updateData = { ...updateData, ...fieldPrompt, id };
    }

    Employee.editEmployee({ id, data: updateData });
  }
}

export default CLI;
