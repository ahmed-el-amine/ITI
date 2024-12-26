package LibraryManagementSystem.Library.Items;

import java.io.Console;
import java.util.ArrayList;

import ConsoleLib.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Library.EntityType;
import LibraryManagementSystem.Library.LibraryEntity;
import MenuSystem.Menu;
import MenuSystem.MenuItem;
import MenuSystem.MenuItemAction;
import MessageBox.MessageBox;
import MessageBox.MessageBoxType;

public abstract class LibraryItem extends LibraryEntity {
    protected String title;

    public LibraryItem(String title, EntityType ItemType)
    {
        super(ItemType);
        this.title = title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public void getItemDetails()
    {
        System.out.println("ID: " + this.getId() + " Title: " + this.getTitle());
    }

    public static MenuItemAction addNewLibraryItemMenu()
    {
        return () -> 
        {
            MenuItem item1 = new MenuItem("Create: Book", Book.addNewItemAction());

            MenuItem item2 = new MenuItem("Create: Magazine", Magazine.addNewItemAction());
            
            Menu mainMenu = new Menu("Create Menu");

            mainMenu.addMenuItem(item1);
            mainMenu.addMenuItem(item2);

            mainMenu.showMenu();
        };
    }

    public static MenuItemAction updateLibraryItemMenu()
    {
        return () -> 
        {
            ArrayList<LibraryEntity> items = Constants.library.getAllLibraryItems();

            if (items.stream().filter(x -> x.getEntityType() != EntityType.Client).count() <= 0) 
            {
                ConsoleLib.Console.clearConsole();
                MessageBox.showMessage("Empty Library", "No Library Items To Display", MessageBoxType.Info);
                
                Menu.pressEnterToBackMessage();
                return;
            }

            Menu mainMenu = new Menu("Update/Display Library Items");
            // Show All Items except the clients
            
            items.stream().filter(x -> x.getEntityType() != EntityType.Client).forEach(x -> {
                LibraryItem item = (LibraryItem)x;
                MenuItem op = new MenuItem("[" + item.entityType.toString() + "] " + item.title);

                op.setAction(updateItemAction(item, op));

                mainMenu.addMenuItem(op);
            });

            mainMenu.showMenu();
            
        };
    }

    public static MenuItemAction updateItemAction(LibraryItem libraryItem, MenuItem op)
    {
        return () -> {
            ConsoleLib.Console.clearConsole();
            Console console = System.console();


            System.out.println("Change Title For : [" + libraryItem.getTitle() + "]");

            while (true) 
            {
                String title = "";

                while (title.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter New Title For The " + libraryItem.entityType.toString() + " : " + ConsoleColors.BLUE);

                        title = console.readLine();

                    if (title.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter Title For The " + libraryItem.entityType.toString() + "" + ConsoleColors.RESET);
                    }
                }

                libraryItem.setTitle(title);
                // Update Option title
                op.setItemText(title);

                MessageBox.showMessage("Successful", "You Have Update The Title For " + libraryItem.entityType.toString(), MessageBoxType.Successful);
                
                Menu.pressEnterToBackMessage();
                break;
            }
        };
    }
   
}
