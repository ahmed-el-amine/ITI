import Navbar from "@/components/assets/Navbar";
import { PropsWithChildren } from "react";

const MainLayout = ({ children }: PropsWithChildren) => {
  return (
    <div>
      <Navbar />
      <div className="container mx-auto px-4 md:px-8 lg:px-16 py-3">{children}</div>
    </div>
  );
};

export default MainLayout;
