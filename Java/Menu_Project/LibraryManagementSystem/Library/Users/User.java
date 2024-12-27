package LibraryManagementSystem.Library.Users;

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

public class User extends LibraryEntity {
    protected String name;
    protected String email;

    public User(String name, String email, EntityType entityType) {
        super(entityType);
        this.name = name;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void getUserDetails() {
        System.err.println("Name: " + name + " Email: " + email);
    }

    public static MenuItemAction updateLibraryItemMenu() {
        return () -> {
            ArrayList<LibraryEntity> items = Constants.library.getAllLibraryItems();

            if (items.stream().filter(x -> x.getEntityType() == EntityType.Client).count() <= 0) {
                ConsoleLib.Console.clearConsole();
                MessageBox.showMessage("Empty Library", "No Library Clients To Display", MessageBoxType.Info);

                Menu.pressEnterToBackMessage();
                return;
            }

            Menu mainMenu = new Menu("Update/Display Library Clients");
            // Show All Items except the clients

            items.stream().filter(x -> x.getEntityType() == EntityType.Client).forEach(x -> {
                Client item = (Client) x;
                MenuItem op = new MenuItem(
                        "[" + item.entityType.toString() + "] [Name] " + item.name + " [Email] " + item.email);

                op.setAction(updateItemAction(item, op));

                mainMenu.addMenuItem(op);
            });

            mainMenu.showMenu();

        };
    }

    public static MenuItemAction updateItemAction(Client client, MenuItem op) {
        return () -> {
            ConsoleLib.Console.clearConsole();
            Console console = System.console();

            System.out.println("Change Name For : [" + client.getName() + "]");

            while (true) {
                String newName = "";

                while (newName.length() <= 0) {
                    System.out.print(ConsoleColors.CYAN + "Please Enter New Name For The " +
                            client.entityType.toString() + " : " + ConsoleColors.BLUE);

                    newName = console.readLine();

                    if (newName.length() <= 0) {
                        System.out.println(ConsoleColors.RED + "Please Enter New Name For The " +
                                client.entityType.toString() + "" + ConsoleColors.RESET);
                    }
                }

                client.setName(newName);
                // Update Option title
                op.setItemText(newName);

                MessageBox.showMessage("Successful", "You Have Update The Name For " +
                        client.entityType.toString(), MessageBoxType.Successful);

                Menu.pressEnterToBackMessage();
                break;
            }
        };
    }

}
