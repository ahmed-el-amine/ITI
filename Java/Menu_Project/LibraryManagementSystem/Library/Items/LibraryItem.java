package LibraryManagementSystem.Library.Items;

import java.io.Console;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import ConsoleLib.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Library.EntityType;
import LibraryManagementSystem.Library.LibraryEntity;
import LibraryManagementSystem.Library.Users.Client;
import MenuSystem.Menu;
import MenuSystem.MenuItem;
import MenuSystem.MenuItemAction;
import MessageBox.MessageBox;
import MessageBox.MessageBoxType;

public abstract class LibraryItem extends LibraryEntity {
    protected String title;
    protected Client borrowedBy = null;

    public LibraryItem(String title, EntityType ItemType) {
        super(ItemType);
        this.title = title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public void getItemDetails() {
        System.out.println("ID: " + this.getId() + " Title: " + this.getTitle());
    }

    public void borroweItem(Client client) {
        if (isBorrowed())
            return;
        this.borrowedBy = client;
    }

    public Client getBorrowedBy() {
        return borrowedBy;
    }

    public void releaseBorrow() {
        if (!isBorrowed())
            return;
        this.borrowedBy = null;
    }

    public boolean isBorrowed() {
        return borrowedBy != null;
    }

    public static MenuItemAction addNewLibraryItemMenu() {
        return () -> {
            MenuItem item1 = new MenuItem("Create: Book", Book.addNewItemAction());

            MenuItem item2 = new MenuItem("Create: Magazine", Magazine.addNewItemAction());

            Menu mainMenu = new Menu("Create Menu");

            mainMenu.addMenuItem(item1);
            mainMenu.addMenuItem(item2);

            mainMenu.showMenu();
        };
    }

    public static MenuItemAction updateLibraryItemMenu() {
        return () -> {
            ArrayList<LibraryEntity> items = Constants.library.getAllLibraryItems();

            if (items.stream().filter(x -> x.getEntityType() != EntityType.Client).count() <= 0) {
                ConsoleLib.Console.clearConsole();
                MessageBox.showMessage("Empty Library", "No Library Items To Display", MessageBoxType.Info);

                Menu.pressEnterToBackMessage();
                return;
            }

            Menu mainMenu = new Menu("Update/Display Library Items");
            // Show All Items except the clients

            items.stream().filter(x -> x.getEntityType() != EntityType.Client).forEach(x -> {
                LibraryItem item = (LibraryItem) x;
                MenuItem op = new MenuItem("[" + item.entityType.toString() + "] " + item.title);

                op.setAction(updateItemAction(item, op));

                mainMenu.addMenuItem(op);
            });

            mainMenu.showMenu();

        };
    }

    public static MenuItemAction updateItemAction(LibraryItem libraryItem, MenuItem op) {
        return () -> {
            ConsoleLib.Console.clearConsole();
            Console console = System.console();

            System.out.println("Change Title For : [" + libraryItem.getTitle() + "]");

            while (true) {
                String title = "";

                while (title.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter New Title For The "
                            + libraryItem.entityType.toString() + " : " + ConsoleColors.BLUE);

                    title = console.readLine();

                    if (title.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter Title For The "
                                + libraryItem.entityType.toString() + "" + ConsoleColors.RESET);
                    }
                }

                libraryItem.setTitle(title);
                // Update Option title
                op.setItemText(title);

                MessageBox.showMessage("Successful",
                        "You Have Update The Title For " + libraryItem.entityType.toString(),
                        MessageBoxType.Successful);

                Menu.pressEnterToBackMessage();
                break;
            }
        };
    }

    public static MenuItemAction borrowItemAction() {
        return () -> {
            MenuItem item1 = new MenuItem("Borrow Item To Client", LibraryItem.borrowItemToClientAction());
            MenuItem item2 = new MenuItem("Show All Borrowd Library Items", LibraryItem.showAllBorrowedItemAction());

            Menu menu = new Menu("Manage Borrowd Items Menu");

            menu.addMenuItem(item1);
            menu.addMenuItem(item2);

            menu.showMenu();
        };
    }

    public static MenuItemAction borrowItemToClientAction() {
        return () -> {
            List<LibraryItem> items = Constants.library.getAllLibraryItems().stream().filter(x -> {
                if ((x.getEntityType() != EntityType.Client)) {
                    LibraryItem m = (LibraryItem) x;
                    if (!m.isBorrowed())
                        return true;
                }
                return false;
            })
                    .map(x -> (LibraryItem) x)
                    .collect(Collectors.toList());

            if (items.size() <= 0) {
                ConsoleLib.Console.clearConsole();
                MessageBox.showMessage("No Items To Borrow", "There is no items to Borrow to any client",
                        MessageBoxType.Info);
                Menu.pressEnterToBackMessage();

                return;
            }

            Menu mainMenu = new Menu("Borrow Item To Client");
            mainMenu.setMenuHeaderNote("Please Select Library Item");
            items.forEach(x -> {
                mainMenu.addMenuItem(new MenuItem("[" + x.getEntityType().toString() + "] " + x.getTitle(),
                        selectClientToBorrowItemAction(x)));
            });

            mainMenu.showMenu();

        };
    }

    private static MenuItemAction selectClientToBorrowItemAction(LibraryItem libraryItem) {
        return () -> {
            List<Client> clients = Constants.library.getAllLibraryItems().stream()
                    .filter(x -> x.getEntityType() == EntityType.Client)
                    .map(x -> (Client) x)
                    .collect(Collectors.toList());

            if (clients.size() <= 0) {
                ConsoleLib.Console.clearConsole();
                MessageBox.showMessage("No Clients To Borrow",
                        "There is no clients to borrow this [" + libraryItem.getEntityType().toString() + "] ["
                                + libraryItem.getTitle() + "]",
                        MessageBoxType.Info);
                Menu.pressEnterToBackMessage();
                return;
            }

            Menu mainMenu = new Menu("Borrow Item To Client");
            mainMenu.setMenuHeaderNote("Please Select Client To Borrow This [" + libraryItem.getEntityType().toString()
                    + "] [" + libraryItem.getTitle() + "]");
            clients.forEach(x -> {
                mainMenu.addMenuItem(new MenuItem("[" + x.getEntityType().toString() + "] " + x.getName(), () -> {
                    libraryItem.borroweItem(x);

                    MessageBox.showMessage(
                            "Item Successfully Borrowed", "This [" + libraryItem.getEntityType().toString() + "]["
                                    + libraryItem.getTitle() + "] has been borrowed by [" + x.getName() + "]",
                            MessageBoxType.Successful);
                    Menu.pressEnterToBackMessage();
                }));
            });

            mainMenu.showMenu();

        };
    }

    public static MenuItemAction showAllBorrowedItemAction() {
        return () -> {
            List<LibraryItem> items = Constants.library.getAllLibraryItems().stream().filter(x -> {
                if ((x.getEntityType() != EntityType.Client)) {
                    LibraryItem m = (LibraryItem) x;
                    if (m.isBorrowed())
                        return true;
                }
                return false;
            }).map(x -> (LibraryItem) x)
                    .collect(Collectors.toList());

            if (items.size() <= 0) {
                ConsoleLib.Console.clearConsole();
                MessageBox.showMessage("No Items Borrowed", "There is no items Borrowed to any client",
                        MessageBoxType.Info);
                Menu.pressEnterToBackMessage();

                return;
            }
            Menu mainMenu = new Menu("All Borrowd Library Items");

            items.forEach(x -> {
                LibraryItem m = (LibraryItem) x;
                mainMenu.addMenuItem(new MenuItem("[" + m.getEntityType().toString() + "] Title : [" + m.getTitle()
                        + "] Borrowed To : [" + m.getBorrowedBy().getName() + "]"));
            });

            mainMenu.showMenu();

        };
    }
}
