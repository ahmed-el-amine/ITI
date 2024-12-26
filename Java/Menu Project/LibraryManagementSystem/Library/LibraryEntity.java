package LibraryManagementSystem.Library;

import java.util.UUID;

import LibraryManagementSystem.Library.Items.Book;
import LibraryManagementSystem.Library.Items.LibraryItem;
import LibraryManagementSystem.Library.Items.Magazine;
import LibraryManagementSystem.Library.Users.Client;
import LibraryManagementSystem.Library.Users.User;
import MenuSystem.Menu;
import MenuSystem.MenuItem;
import MenuSystem.MenuItemAction;

public abstract class LibraryEntity {
    protected String id = UUID.randomUUID().toString();
    protected EntityType entityType;

    public LibraryEntity(EntityType ItemType)
    {
        this.entityType = ItemType;
    }

    public String getId() {
        return id;
    }

    public EntityType getEntityType() {
        return entityType;
    }

    public static MenuItemAction manageLibraryEntities()
    {
        return () -> 
        {
            MenuItem item1 = new MenuItem("Library Items", manageLibraryItems());
            MenuItem item2 = new MenuItem("Library Clients", manageLibraryClients());

            Menu mainMenu = new Menu("Manage Library");

            mainMenu.addMenuItem(item1);
            mainMenu.addMenuItem(item2);

            mainMenu.showMenu();
        };
    }

    public static MenuItemAction manageLibraryItems()
    {
        return () -> 
        {
            MenuItem item1 = new MenuItem("Create: Book", Book.addNewItemAction());
            MenuItem item2 = new MenuItem("Create: Magazine", Magazine.addNewItemAction());
            MenuItem item3 = new MenuItem("Update/Display Library Items", LibraryItem.updateLibraryItemMenu());

            Menu mainMenu = new Menu("Manage Library Items");

            mainMenu.addMenuItem(item1);
            mainMenu.addMenuItem(item2);
            mainMenu.addMenuItem(item3);

            mainMenu.showMenu();
        };
    }

    public static MenuItemAction manageLibraryClients()
    {
        return () -> 
        {
            MenuItem item1 = new MenuItem("Create: Client", Client.addNewItemAction());
            MenuItem item2 = new MenuItem("Update/Display Clients", User.updateLibraryItemMenu());

            Menu mainMenu = new Menu("Manage Library Clients");

            mainMenu.addMenuItem(item1);
            mainMenu.addMenuItem(item2);

            mainMenu.showMenu();
        };
    }
}
