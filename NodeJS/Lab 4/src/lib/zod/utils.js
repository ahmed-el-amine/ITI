export const zodValidator = (data, schema) => {
  const { success } = schema.safeParse(data);
  return success;
};
