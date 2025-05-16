import React from "react";
import MainLayout from "../../../Layout/Main.Layout";
import { Outlet } from "react-router";

const AboutLayout = () => {
  return (
    <MainLayout>
      <Outlet />
    </MainLayout>
  );
};

export default AboutLayout;
