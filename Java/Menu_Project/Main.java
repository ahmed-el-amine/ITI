
import LibraryManagementSystem.Auth.Auth;
// import LibraryManagementSystem.Constants.Constants;
// import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import LibraryManagementSystem.Library.Library;
// import LibraryManagementSystem.Library.Items.Book;
// import LibraryManagementSystem.Library.Items.Magazine;
// import LibraryManagementSystem.Library.Users.Client;

public class Main {
    public static void main(String[] args) {
        // Show Login Screen
        Auth.showLogin();
        // Show main menu
        // try {
        // Constants.library.add(new Book("My Book"));
        // Constants.library.add(new Magazine("My Magazine"));
        // Constants.library.add(new Client("Ahmed", "ahmed@gmail.com"));

        // } catch (ItemAlreadyExists e) {
        // e.printStackTrace();
        // }

        Library.showMainMenu();
    }
}