package LibraryManagementSystem.Auth;

import java.io.Console;

import ConsoleLib.ConsoleColors;

public class Auth {
    public static boolean IsAuth = false;

    public static void ShowLogin()
    {
        Console console = System.console();
        
        while (!Auth.IsAuth) {

            System.out.println("Welcome back Mr/Ms User");
            System.out.println("Please Login");
            System.out.print("Enter Your Username: ");

            String Username = console.readLine();

            String Password = String.valueOf(console.readPassword("Enter Your Password: "));

            if (!LoginAuth.Login(Username, Password)) {
                System.out.println(ConsoleColors.RED);
                System.out.println("Username Or Password Is Wrong Please Check Your Data");
                System.out.println(ConsoleColors.RESET);
                
                System.out.print("Do You Want To Try Login Again ? (Y/n) : ");
                
                String option = console.readLine();
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
