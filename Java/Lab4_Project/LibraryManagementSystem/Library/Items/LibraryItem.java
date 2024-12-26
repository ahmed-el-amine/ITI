package LibraryManagementSystem.Library.Items;

import java.io.Console;

import ConsoleLib.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import LibraryManagementSystem.Library.ItemsType;
import LibraryManagementSystem.Library.LibraryEntity;
import MenuSystem.Menu;
import MenuSystem.MenuItem;
import MessageBox.MessageBox;
import MessageBox.MessageBoxType;

public abstract class LibraryItem extends LibraryEntity {
    protected String title;
    private ItemsType ItemType;

    public LibraryItem(String title, ItemsType ItemType)
    {
        this.title = title;
        this.ItemType = ItemType;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public ItemsType getItemType() {
        return ItemType;
    }

    public void getItemDetails()
    {
        System.out.println("ID: " + this.getId() + " Title: " + this.getTitle());
    }

    public static Runnable AddNewLibraryItem()
    {
        return () -> 
        {
            MenuItem item1 = new MenuItem("Create: Book", AddNewItemAction(ItemsType.Book));

            MenuItem item2 = new MenuItem("Create: Magazine", AddNewItemAction(ItemsType.Magazine));
            
            Menu mainMenu = new Menu("Create Menu");

            mainMenu.addMenuItem(item1);
            mainMenu.addMenuItem(item2);

            mainMenu.showMenu();
        };
    }

    public static Runnable AddNewItemAction(ItemsType itemType)
    {
        return () -> 
        {
            ConsoleLib.Console.ClearConsole();
            Console console = System.console();

            while (true) 
            {
                String title = "";

                while (title.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter Title For The " + itemType.toString() + " : " + ConsoleColors.BLUE);

                        title = console.readLine();

                    if (title.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter Title For The " + itemType.toString() + "" + ConsoleColors.RESET);
                    }
                }

                try 
                {
                    switch (itemType) {
                        case Book:
                            Constants.library.add(new Book(title));
                            break;
                        case Magazine:
                            Constants.library.add(new Magazine(title));
                            break;
                    }

                    MessageBox.showMessage("You Have Created A New Item", MessageBoxType.Successful);
                                 
                    System.out.println("Press Enter To Go Back");
                    console.readPassword();
                    break;
                } 
                catch (ItemAlreadyExists e) {
                    System.out.println(e.getMessage());
                }
            }
        };
    }

    public static Runnable UpdateLibraryItem()
    {
        return () -> 
        {
            Menu mainMenu = new Menu("Update/Display Library Items");

            Constants.library.getAllLibraryItems().forEach(x -> {

                MenuItem op = new MenuItem("[" + x.ItemType.toString() + "] " + x.title);

                op.setAction(UpdateItemAction(x, op));

                mainMenu.addMenuItem(op);
            });

            mainMenu.showMenu();
        };
    }

    public static Runnable UpdateItemAction(LibraryItem libraryItem, MenuItem op)
    {
        return () -> {
            ConsoleLib.Console.ClearConsole();
            Console console = System.console();

            System.out.println("Change Title For : [" + libraryItem.getTitle() + "]");

            while (true) 
            {
                String title = "";

                while (title.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter New Title For The " + libraryItem.ItemType.toString() + " : " + ConsoleColors.BLUE);

                        title = console.readLine();

                    if (title.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter Title For The " + libraryItem.ItemType.toString() + "" + ConsoleColors.RESET);
                    }
                }

                libraryItem.setTitle(title);
                // Update Option title
                op.setItemText(title);

                MessageBox.showMessage("You Have Update The Title", MessageBoxType.Successful);
                System.out.println("Press Enter To Go Back");
                
                console.readPassword();
                break;
            }
        };
    }
   
}
