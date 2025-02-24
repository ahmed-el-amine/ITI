export enum Operations {
  GUI = "gui",
  ADD = "add",
  LIST = "list",
  EDIT = "edit",
  DELETE = "delete",
}

export interface ParseArgsReturnProps {
  operation: Operations;
  operationData: string[];
  data: { [key: string]: string };
}

export const parseArgs = (): ParseArgsReturnProps => {
  const result: ParseArgsReturnProps = {
    operation: Operations.GUI,
    operationData: [],
    data: {},
  };

  // get args
  let args = process.argv.slice(2);

  if (args.length === 0) return result;

  // get operation type
  const operationType = args[0];
  if (Object.values(Operations).includes(operationType as Operations)) {
    result.operation = operationType as Operations;
  }

  // remove operation type from args if exists
  args = result.operation ? args.slice(1) : args;

  // loop throw all args and then get operation data and data
  for (const arg of args) {
    if (arg.startsWith("--")) {
      const argAsKeyValue = arg.split("=");
      if (argAsKeyValue.length !== 2) continue;
      const key = argAsKeyValue[0].replace("--", "");
      const value = argAsKeyValue[1];
      result.data[key] = value;
    } else {
      if (arg) result.operationData.push(arg);
    }
  }

  return result;
};
