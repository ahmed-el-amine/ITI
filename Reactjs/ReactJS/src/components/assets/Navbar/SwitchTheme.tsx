import { Check, ChevronsUpDown, Computer, Moon, Sun } from "lucide-react";
import * as React from "react";

import { Button } from "@/components/ui/button";
import { Command, CommandEmpty, CommandGroup, CommandItem, CommandList } from "@/components/ui/command";
import { Popover, PopoverContent, PopoverTrigger } from "@/components/ui/popover";
import { Theme, useTheme } from "@/lib/shadcn/ThemeProvider";
import { cn } from "@/lib/utils";

const themes = [
  {
    value: "light",
    label: "Light",
    icon: <Moon />,
  },
  {
    value: "dark",
    label: "Dark",
    icon: <Sun />,
  },
  {
    value: "system",
    label: "System",
    icon: <Computer />,
  },
];

export function SwitchTheme() {
  const theme = useTheme();
  const [open, setOpen] = React.useState(false);

  const onSelect = (value: string) => {
    theme.setTheme(value as Theme);
    setOpen(false);
  };

  const selectedTheme = themes.find((x) => x.value === theme.theme);

  return (
    <Popover open={open} onOpenChange={setOpen}>
      <PopoverTrigger asChild>
        <Button variant="outline" role="combobox" aria-expanded={open} className="w-[125px] justify-between">
          {selectedTheme && selectedTheme.icon}
          {selectedTheme && selectedTheme.label}
          <ChevronsUpDown className="opacity-50" />
        </Button>
      </PopoverTrigger>
      <PopoverContent className="w-[125px] p-0">
        <Command>
          <CommandList>
            <CommandEmpty>No Theme Found.</CommandEmpty>
            <CommandGroup>
              {themes.map((x) => (
                <CommandItem key={x.value} value={x.value} onSelect={onSelect}>
                  {x.label}
                  <Check className={cn("ml-auto", theme.theme === x.value ? "opacity-100" : "opacity-0")} />
                  {x.icon}
                </CommandItem>
              ))}
            </CommandGroup>
          </CommandList>
        </Command>
      </PopoverContent>
    </Popover>
  );
}

export default SwitchTheme;
