import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "./index.css";
import App from "./App.jsx";
import { BrowserRouter, Route, Routes } from "react-router";
import AboutLayout from "./components/About/index.jsx";
import Me from "./components/About/Me.jsx";
import About from "./components/About/About.jsx";
import Shuffle from "./components/Shuffle.jsx";
import Shop from "./components/Shop/index.jsx";
import AddProduct from "./components/Shop/AddProduct.jsx";

createRoot(document.getElementById("root")).render(
  <StrictMode>
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<App />} />
        <Route path="about" element={<About />} />

        <Route path="about" element={<AboutLayout />}>
          <Route index element={<About />} />
          <Route path="me" element={<Me />} />
        </Route>

        <Route path="/shuffle" element={<Shuffle />} />
        <Route path="/shop" element={<Shop />} />
        <Route path="/addProduct" element={<AddProduct />} />
      </Routes>
    </BrowserRouter>
  </StrictMode>
);
