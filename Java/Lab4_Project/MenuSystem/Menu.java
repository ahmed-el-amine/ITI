package MenuSystem;
import Console.*;
import LibraryManagementSystem.Library.LibraryItem;
import Validation.Validation;

import java.util.ArrayList;
import java.util.Scanner;

public class Menu {
    private String menuTitle = null;
    private ArrayList<MenuItem> menuItems = new ArrayList<MenuItem>();

    public Menu(String menuTitle)
    {
        this.menuTitle = menuTitle;
    }

    public void AddMenuItem(MenuItem item)
    {
        menuItems.add(item);
    }

    public void ShowMenu()
    {
        this.PrintMenu();
        this.CatchKeyboard();
    }

    private void PrintMenu()
    {
        // First Clear Console
        Console.ClearConsole();

        System.out.println(ConsoleColors.CYAN_UNDERLINED + this.menuTitle + ConsoleColors.RESET);
        System.out.println();

        for (int i = 0; i < menuItems.size(); i++) {
            MenuItem menuItem = menuItems.get(i);
            System.out.print(ConsoleColors.CYAN + (i + 1) + ConsoleColors.RESET);
            System.out.println("- " + menuItem.getTitle());
        }

        System.out.println();

        System.out.println(ConsoleColors.YELLOW + "(Q/q) For Exit");
        System.out.print(ConsoleColors.CYAN);
        System.out.print("Please Select Option From [1] To ["+ menuItems.size() +"] : ");
        System.out.print(ConsoleColors.RESET);
    }

    private void CatchKeyboard()
    {
        Scanner scanner = new Scanner(System.in);

        boolean isRunning = true;
        while (isRunning) 
        {
            try 
            {
                System.out.print(ConsoleColors.BLUE_BOLD);
                
                String option = scanner.nextLine();

                System.out.print(ConsoleColors.RESET);

                if (option.equalsIgnoreCase("q")) return;

                if (!Validation.isValidInt(option)) 
                {
                    System.out.println(ConsoleColors.RED + "Please Enter Valid Number" + ConsoleColors.RESET);
                }
                else
                {
                    int optionAsInt = Integer.parseInt(option);
                    if (optionAsInt <= 0 || optionAsInt > this.menuItems.size()) 
                    {
                        System.out.println(ConsoleColors.RED + "Please Enter Valid Option Between [1] To ["+ this.menuItems.size() +"] " + ConsoleColors.RESET);
                    }
                    else
                    {
                        MenuItem selectedItem = this.menuItems.get(optionAsInt - 1);
                        
                        if (selectedItem.getAction() == null) return;
                        
                        selectedItem.startAction();
                        this.PrintMenu();
                    }
                }    
            } 
            catch (Exception e)
            {
                System.out.println(ConsoleColors.RED + "An error occurred: " + e.getMessage() + ConsoleColors.RESET);
            }
        }

        scanner.close();
    }

   
}
