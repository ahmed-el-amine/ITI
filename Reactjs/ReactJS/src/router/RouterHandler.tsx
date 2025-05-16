import Home from "@/components/pages/Home";
import { BrowserRouter, Routes, Route } from "react-router";
const RouterHandler = () => {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
      </Routes>
    </BrowserRouter>
  );
};

export default RouterHandler;
