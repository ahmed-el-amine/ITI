import LibraryManagementSystem.Library.Library;
import MenuSystem.Menu;
import MenuSystem.MenuItem;

public class Main {
    public static void main(String[] args) {
        // Show Login Screen
        // Auth.showLogin();
      
        
        // Library.ShowMainMenu().run();

        MenuItem i1 = new MenuItem("1111111111111111111", () -> {
            MenuItem i2 = new MenuItem("33333333333", () -> {
                MenuItem i3 = new MenuItem("33333333333");
                Menu m3 = new Menu("33333333333 Memu");
                m3.AddMenuItem(i3);
                m3.ShowMenu();
            });
            Menu m2 = new Menu("222222222222222 Memu");
            m2.AddMenuItem(i2);
            m2.AddMenuItem(new MenuItem("back"));
            m2.ShowMenu();


        });

        Menu m1 = new Menu("1111111111111111111 Menu");
        m1.AddMenuItem(i1);


        m1.ShowMenu();

      
    }
}