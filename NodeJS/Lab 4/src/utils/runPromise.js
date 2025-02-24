const runPromise = async (promise) => {
  try {
    const data = await promise;
    return [null, data]; // Success: err = null, data = resolved value
  } catch (err) {
    return [err, null]; // Error: err = error object, data = null
  }
};

export default runPromise;
