import React from "react";
import MainLayout from "../../../Layout/Main.Layout";

const AddProduct = () => {
  return (
    <MainLayout>
      <div className="flex justify-center items-center h-screen">
        <form className="flex flex-col gap-4 w-1/4">
          <input type="text" placeholder="Name" className="input w-full" />
          <input type="number" placeholder="Price" className="input w-full" />

          <button className="btn">add Product</button>
        </form>
      </div>
    </MainLayout>
  );
};

export default AddProduct;
