package LibraryManagementSystem.Library;

import java.util.ArrayList;

import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import LibraryManagementSystem.Exceptions.ItemNotFoundException;
import MenuSystem.Menu;
import MenuSystem.MenuItem;

public class Library<T extends LibraryItem> {
    private ArrayList<T> collectionArrayList = new ArrayList<T>();
    
    public static Runnable ShowMainMenu()
    {
        return ()-> 
        {
            MenuItem item1 = new MenuItem("Create", LibraryItem.AddNewLibraryItem());
            // init Menu
            Menu mainMenu = new Menu("Manage Library Main Menu");

            // add menu items to main menu
            mainMenu.AddMenuItem(item1);

            // show menu
            mainMenu.ShowMenu();
        };
    }


    public void Add(T libraryItem) throws ItemAlreadyExists
    {
        // check if id exists
        for (int i = 0; i < collectionArrayList.size(); i++) {
            if (collectionArrayList.get(i).getId() == libraryItem.getId())
            {
                throw new ItemAlreadyExists("Item With ID [" + libraryItem.getId() + "] Alrady Exists Cannot Create Two With The Same ID");
            }
        }

        collectionArrayList.add(libraryItem);
    }

    public T FindBookByID(int id) throws ItemNotFoundException
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
        throw new ItemNotFoundException("Book With Id ["+ id +"] Not Found");
    }

    public T FindMagazineByID(int id) throws ItemNotFoundException
    {
        for (int i = 0; i < collectionArrayList.size(); i++) {
            if (collectionArrayList.get(i) instanceof Magazine)
            {
                if (collectionArrayList.get(i).getId() == id)
                {
                    return collectionArrayList.get(i);
                }
            }
        }
        throw new ItemNotFoundException("Magazine With Id ["+ id +"] Not Found");
    }

    public void display()
    {
        for (T t : collectionArrayList) {
            System.out.println("ID:" + t.getId() + " Title:" + t.getTitle());
        }
    }
}
