import { Button } from "@/components/ui/button";
import { Home } from "lucide-react";

interface MenuItemProps {
  text: string;
  icon: unknown;
}

const MenuItemsConfig: MenuItemProps[] = [
  {
    text: "Home",
    icon: Home,
  },
];

const MenuItems = () => {
  return (
    <div className="flex items-center gap-2">
      {MenuItemsConfig.map((e, idx) => {
        return (
          <Button variant="link" key={e.text + idx}>
            {e.text}
          </Button>
        );
      })}
    </div>
  );
};

export default MenuItems;
