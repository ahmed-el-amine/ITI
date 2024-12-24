package LibraryManagementSystem.Library;

import MenuSystem.Menu;
import MenuSystem.MenuItem;

public abstract class LibraryItem {
    private int id;
    private String title;

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
            MenuItem item1 = new MenuItem("Create: Book", Book.AddNewBookAction());

            MenuItem item2 = new MenuItem("Create: Magazine");

            MenuItem item3 = new MenuItem("Back To Main Menu", Library.ShowMainMenu());
            
            Menu mainMenu = new Menu("Create Menu");

            mainMenu.AddMenuItem(item1);
            mainMenu.AddMenuItem(item2);
            mainMenu.AddMenuItem(item3);

            mainMenu.ShowMenu();
        };
    }

   
}
