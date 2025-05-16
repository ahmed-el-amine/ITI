import React from "react";
import MainLayout from "../../../Layout/Main.Layout";
import Product from "./Product";
import { useEffect } from "react";

const Shop = () => {
  const [products, setProducts] = React.useState([]);

  useEffect(() => {
    fetch("http://localhost:3000/products")
      .then((res) => res.json())
      .then((data) => setProducts(data))
      .catch((err) => console.log(err));
  }, []);

  return (
    <MainLayout>
      <div className="flex flex-wrap gap-4 justify-center items-center h-screen">
        {products.map(({ title, description, images: [one], price }) => {
          return <Product name={title} description={description} image={one} price={price} />;
        })}
      </div>
    </MainLayout>
  );
};

export default Shop;
