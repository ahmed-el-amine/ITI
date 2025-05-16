import { ThemeProvider } from "@/lib/shadcn/ThemeProvider";
import RouterHandler from "@/router/RouterHandler";

const AppWrapper = () => {
  return (
    <ThemeProvider>
      <RouterHandler />
    </ThemeProvider>
  );
};

export default AppWrapper;
