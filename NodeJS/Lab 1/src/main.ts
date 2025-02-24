import DB from "./db";
import path from "path";
import { Operations, parseArgs } from "./utils/args";
import Employee from "./controllers/Employee";
import CLI from "./controllers/CLI";
const main = async () => {
  // create DB
  DB.createDB({
    fileName: "db.json",
    path: path.join(__dirname, "../", "database"),
  });

  // fake args
  // process.argv.push("add", "--name=Foo", "--email=ahmed@gamil.com", "--salary=123", "--level=Jr", "--yearsOfExperience=1");
  // process.argv.push("delete", "--id=1");
  // process.argv.push("edit", "dd", "--id=2", "--name=Foo", "--email=yy@gamil.com", "--salary=123", "--level=Jr", "--yearsOfExperience=555");
  // process.argv.push("delete", "1", "--id=2", "--name=Foo", "--email=yy@gamil.com", "--salary=123", "--level=Jr", "--yearsOfExperience=555");
  // process.argv.push("list", "16");
  // process.argv.push("list", "--name=Foo", "--level=Jr", "--yearsOfExperience=1", "--email=ahmeaaad@gamil.com");
  // process.argv.push("list", "--salary=123");
  // process.argv.push("list");

  const args = parseArgs();

  switch (args.operation) {
    case Operations.ADD:
      await Employee.addEmployee({ data: args.data });
      break;
    case Operations.LIST:
      await Employee.listEmployee(args);
      break;
    case Operations.EDIT:
      await Employee.editEmployee({ id: args.operationData[0], data: args.data });
      break;
    case Operations.DELETE:
      await Employee.deleteEmployee({ id: args.operationData[0] });
      break;
    default:
      CLI.showMainMenu();
      break;
  }
};

main();
