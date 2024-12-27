package MenuSystem;

import Validation.Validation;

import java.io.Console;
import java.util.ArrayList;

import ConsoleLib.*;

public class Menu {
    private String menuTitle = null;
    private String menuHeaderNote = null;
    private ArrayList<MenuItem> menuItems = new ArrayList<MenuItem>();

    public Menu(String menuTitle) {
        this.menuTitle = menuTitle;
    }

    public void addMenuItem(MenuItem item) {
        menuItems.add(item);
    }

    public void setMenuTitle(String menuTitle) {
        this.menuTitle = menuTitle;
    }

    public void setMenuHeaderNote(String menuHeaderNote) {
        this.menuHeaderNote = menuHeaderNote;
    }

    public void showMenu() {
        this.printMenu();
        this.catchKeyboard();
    }

    private void printMenu() {
        // First Clear Console
        ConsoleLib.Console.clearConsole();

        System.out.println(ConsoleColors.CYAN_UNDERLINED + this.menuTitle + ConsoleColors.RESET);
        System.out.println();

        if (this.menuHeaderNote != null) {
            System.out.println(ConsoleColors.CYAN + this.menuHeaderNote + ConsoleColors.RESET);
        }

        for (int i = 0; i < menuItems.size(); i++) {
            MenuItem menuItem = menuItems.get(i);
            System.out.print(ConsoleColors.CYAN + (i + 1) + ConsoleColors.RESET);
            System.out.println("- " + menuItem.getItemText());
        }

        System.out.print(ConsoleColors.CYAN + "q" + ConsoleColors.RESET);
        System.out.println(ConsoleColors.YELLOW + "- Go Back/Exit" + ConsoleColors.RESET);

        System.out.println();

        System.out.print(ConsoleColors.CYAN);
        System.out.print("Please Select Option : ");
        System.out.print(ConsoleColors.RESET);
    }

    private void catchKeyboard() {
        Console console = System.console();

        boolean isRunning = true;
        try {
            while (isRunning) {
                System.out.print(ConsoleColors.BLUE_BOLD);

                String option = console.readLine();

                System.out.print(ConsoleColors.RESET);

                if (option.equalsIgnoreCase("q"))
                    return;

                if (!Validation.isValidInt(option)) {
                    System.out.println(ConsoleColors.RED + "Please Enter Valid Number" + ConsoleColors.RESET);
                } else {
                    int optionAsInt = Integer.parseInt(option);
                    if (optionAsInt <= 0 || optionAsInt > this.menuItems.size()) {
                        System.out.println(ConsoleColors.RED + "Please Enter Valid Option Between [1] To ["
                                + this.menuItems.size() + "] " + ConsoleColors.RESET);
                    } else {
                        MenuItem selectedItem = this.menuItems.get(optionAsInt - 1);

                        if (selectedItem.hasAction()) {
                            selectedItem.startAction();

                            this.printMenu();
                        } else {
                            System.out.print(ConsoleColors.CYAN);
                            System.out.print("Please Select Option : ");
                            System.out.print(ConsoleColors.RESET);
                        }
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(ConsoleColors.RED + "An error occurred: " + e.getMessage() + ConsoleColors.RESET);
        }
    }

    public static void pressEnterToBackMessage() {
        Console console = System.console();
        System.out.println("Press Enter To Go Back...");
        console.readPassword();
    }

}
