package LibraryManagementSystem.Auth;

import java.io.Console;
import java.util.Scanner;

import Console.ConsoleColors;

public class Auth {
    public static boolean IsAuth = false;

    public static void showLogin()
    {
        try (Scanner scanner = new Scanner(System.in)) 
        {
            while (!Auth.IsAuth) {
                Console console = System.console();

                System.out.println("Welcome back Mr/Ms User");
                System.out.println("Please Login");
                System.out.print("Enter Your Username: ");
                String Username = scanner.nextLine();

                String Password = String.valueOf(console.readPassword("Enter Your Password: "));

                if (!LoginAuth.Login(Username, Password)) {
                    System.out.println(ConsoleColors.RED);
                    System.out.println("Username Or Password Is Wrong Please Check Your Data");
                    System.out.println(ConsoleColors.RESET);
                    
                    System.out.print("Do You Want To Try Login Again ? (N/n) : ");
                    
                    String option = scanner.nextLine();
                    if (option.equals("n") || option.equals("N")) 
                    {
                        System.out.println(ConsoleColors.CYAN);
                        System.err.println("See You Later Fake: " + Username + " :)");
                        System.out.println(ConsoleColors.RESET);
                        System.exit(0);
                    }
                }
            }
        }
    }
}
