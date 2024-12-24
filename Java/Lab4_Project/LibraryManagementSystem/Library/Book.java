package LibraryManagementSystem.Library;
import java.util.Scanner;
import Console.ConsoleColors;
import LibraryManagementSystem.Constants.Constants;
import LibraryManagementSystem.Exceptions.ItemAlreadyExists;
import Validation.Validation;

public class Book extends LibraryItem {
    public Book(int bookID, String bookTitle)
    {
        super(bookID, bookTitle);
    }

    public static Runnable AddNewBookAction()
    {
        return () -> 
        {
            Console.Console.ClearConsole();

            try (Scanner scanner = new Scanner(System.in)) 
            {
                while (true) 
                {
                    String id = null;

                    while (!Validation.isValidInt(id) || Integer.parseInt(id) <= 0) 
                    {
                        System.out.print(ConsoleColors.CYAN + "Please Enter ID For The Book : " + ConsoleColors.BLUE);
                        id = scanner.nextLine();

                        if (!Validation.isValidInt(id) || Integer.parseInt(id) <= 0) {
                            System.out.println(ConsoleColors.RED + "Wring ID Format Please Enter Valid Number Start From 1"+ ConsoleColors.RESET);
                        }
                    }

                    String title = "";

                    while (title.length() <= 0) {
                        System.out.print(ConsoleColors.CYAN + "Please Enter Title For The Book : " + ConsoleColors.BLUE);

                        title = scanner.nextLine();

                        if (title.length() <= 0) {
                            System.out.println(ConsoleColors.RED + "Please Enter Title For The Book"+ ConsoleColors.RESET);
                        }
                    }

                    try 
                    {
                        Constants.library.Add(new Book(Integer.parseInt(id), title));

                        // LibraryItem.AddNewLibraryItem().run();
                        break;
                    } 
                    catch (ItemAlreadyExists e) {
                        System.out.println("This ID: " + id + " Alrady Exist Please Select Another ID");
                    }
                }
            }
        };
    }
}
