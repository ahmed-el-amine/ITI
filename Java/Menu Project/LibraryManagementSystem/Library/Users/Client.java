package LibraryManagementSystem.Library.Users;

import java.io.Console;

import ConsoleLib.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import LibraryManagementSystem.Library.EntityType;
import MenuSystem.Menu;
import MenuSystem.MenuItemAction;
import MessageBox.MessageBox;
import MessageBox.MessageBoxType;

public class Client extends User {
    public Client(String name, String email)
    {
        super(name, email, EntityType.Client);
    }

     public static MenuItemAction addNewItemAction()
    {
        return () -> 
        {
            ConsoleLib.Console.clearConsole();
            Console console = System.console();

            while (true) 
            {
                String name = "";
                String email = "";

                while (name.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter Name For The Client : " + ConsoleColors.BLUE);

                        name = console.readLine();

                    if (name.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter Name For The Client" + ConsoleColors.RESET);
                    }
                }

                try 
                {
                    Constants.library.add(new Client(name, email));

                    MessageBox.showMessage("Successful", "You Have Created A New Client", MessageBoxType.Successful);
                                 
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
