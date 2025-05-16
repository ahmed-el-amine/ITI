import React from "react";

const Reset = ({ data, setItems }) => {
  return (
    <button className="btn btn-error" onClick={() => setItems(data)}>
      reset
    </button>
  );
};

export default Reset;
