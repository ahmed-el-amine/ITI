package LibraryManagementSystem.Library;
import java.util.ArrayList;
import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import LibraryManagementSystem.Exceptions.ItemNotFoundException;
import MenuSystem.Menu;
import MenuSystem.MenuItem;

public class Library<T extends LibraryItem> {
    private ArrayList<T> collectionArrayList = new ArrayList<T>();
    
    public static void ShowMainMenu()
    {
        MenuItem item1 = new MenuItem("Add New Library Item", LibraryItem.AddNewLibraryItem());
        MenuItem item2 = new MenuItem("Update/Display Library Items", LibraryItem.UpdateLibraryItem());
        // MenuItem item2 = new MenuItem("Create New Client", LibraryItem.AddNewLibraryItem());
        
        // init Menu
        Menu mainMenu = new Menu("Manage Library Main Menu");

        // add menu items to main menu
        mainMenu.addMenuItem(item1);
        mainMenu.addMenuItem(item2);

        // show menu
        mainMenu.showMenu();
    }

    public void add(T libraryItem) throws ItemAlreadyExists
    {
        // check if id exists
        if (this.isIdExists(libraryItem.getId())) {
            throw new ItemAlreadyExists(libraryItem.ItemType.toString() + " with id [" + libraryItem.getId() + "] alrady exists cannot create two " + libraryItem.ItemType.toString() + " with the same id");
        }
        collectionArrayList.add(libraryItem);
    }

    public boolean isIdExists(int id)
    {
        return collectionArrayList.stream().anyMatch(x -> x.getId() == id);
    }

    public T findItemById(int id) throws ItemNotFoundException
    {
        for (int i = 0; i < collectionArrayList.size(); i++) {
            if (collectionArrayList.get(i) instanceof Book)
            {
                if (collectionArrayList.get(i).getId() == id)
                {
                    return collectionArrayList.get(i);
                }
            }
        }
        throw new ItemNotFoundException("Item with id ["+ id +"] is not exist");
    }

    public ArrayList<T> getAllLibraryItems() {
        return collectionArrayList;
    }

    public void display()
    {
        for (T t : collectionArrayList) {
            System.out.println("ID:" + t.getId() + " Title:" + t.getTitle());
        }
    }
}
