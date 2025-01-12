function isValidInt(value) {
  if (!isNaN(parseInt(value))) return { status: true, value: parseInt(value) };
  return { status: false, value: 0 };
}
