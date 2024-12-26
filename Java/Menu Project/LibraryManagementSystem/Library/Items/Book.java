package LibraryManagementSystem.Library.Items;

import java.io.Console;

import ConsoleLib.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import LibraryManagementSystem.Library.EntityType;
import MenuSystem.Menu;
import MenuSystem.MenuItemAction;
import MessageBox.MessageBox;
import MessageBox.MessageBoxType;

public class Book extends LibraryItem {
    public Book(String bookTitle)
    {
        super(bookTitle, EntityType.Book);
    }

    public static MenuItemAction addNewItemAction()
    {
        return () -> 
        {
            ConsoleLib.Console.clearConsole();
            Console console = System.console();

            while (true) 
            {
                String title = "";

                while (title.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter Title For The Book : " + ConsoleColors.BLUE);

                        title = console.readLine();

                    if (title.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter Title For The Book" + ConsoleColors.RESET);
                    }
                }

                try 
                {
                    Constants.library.add(new Book(title));

                    MessageBox.showMessage("Successful", "You Have Created A New Book", MessageBoxType.Successful);
                                 
                    Menu.pressEnterToBackMessage();
                    break;
                } 
                catch (ItemAlreadyExists e) {
                    System.out.println(e.getMessage());
                }
            }
        };
    }
}
