package LibraryManagementSystem.Library;

import java.io.Console;

import ConsoleLib.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import MenuSystem.Menu;
import MenuSystem.MenuItem;
import MessageBox.MessageBox;
import MessageBox.MessageBoxType;
import Validation.Validation;

public abstract class LibraryItem {
    private int id;
    private String title;
    public final ItemsType ItemType = ItemsType.Book;

    public LibraryItem(int id, String title)
    {
        this.id = id;
        this.title = title;
    }

    public int getId() {
        return id;
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
                String id = null;

                while (!Validation.isValidInt(id) || Integer.parseInt(id) <= 0) 
                {
                    System.out.print(ConsoleColors.CYAN + "Please Enter ID For The " + itemType.toString() + " : " + ConsoleColors.BLUE);
                    id = console.readLine();

                    if (!Validation.isValidInt(id) || Integer.parseInt(id) <= 0) {
                        System.out.println(ConsoleColors.RED + "Wring ID Format Please Enter Valid Number Start From 1"+ ConsoleColors.RESET);
                    }
                    else if (Constants.library.isIdExists(Integer.parseInt(id))) 
                    {
                        System.out.println(ConsoleColors.RED + "This ID: " + id + " Alrady Exist Please Select Another ID" + ConsoleColors.RESET);
                        id  = "";                            
                    }
                }

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
                            Constants.library.add(new Book(Integer.parseInt(id), title));
                            break;
                        case Magazine:
                            Constants.library.add(new Magazine(Integer.parseInt(id), title));
                            break;
                    }

                    MessageBox.showMessage("You Have Created A New Item", MessageBoxType.Error);
                                 
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
                mainMenu.addMenuItem(new MenuItem("[" + x.ItemType.toString() + "] " + x.title, UpdateItemAction(x)));
            });

            mainMenu.showMenu();
        };
    }

    public static Runnable UpdateItemAction(LibraryItem libraryItem)
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

                MessageBox.showMessage("You Have Update The Title", MessageBoxType.Successful);
                                 
                System.out.println("Press Enter To Go Back");
                
                console.readPassword();
                break;
            }
        };
    }
   
}
