import { Button } from "@/components/ui/button";
import MenuItems from "./MenuItems";
import SwitchTheme from "./SwitchTheme";

const Navbar = () => {
  return (
    <div className="border-grid sticky top-0 z-50 w-full border-b bg-background/95 backdrop-blur supports-[backdrop-filter]:bg-background/60">
      <div className="container mx-auto px-4 md:px-8 lg:px-16 flex justify-between items-center py-3">
        <div className="flex items-center gap-4">
          <h1 className="text-2xl font-bold">Blogs</h1>
          <MenuItems />
        </div>
        <div className="flex items-center gap-4">
          <SwitchTheme />
          {/* <Button variant="outline" size="icon" className="relative">
            <Badge variant={"destructive"} className="absolute top-[-10px] left-[-10px]">
              5
            </Badge>
            <ShoppingCart />
          </Button> */}
          <Button variant="default">Login</Button>
        </div>
      </div>
    </div>
  );
};

export default Navbar;
