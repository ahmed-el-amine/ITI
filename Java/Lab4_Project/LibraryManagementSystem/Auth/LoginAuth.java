package LibraryManagementSystem.Auth;

public class LoginAuth {
    private static final String username = "admin";
    private static final String password = "admin";

    public static boolean Login(String username, String password)
    {
        LoginAuth.Loading();
        if (LoginAuth.username.equals(username) && LoginAuth.password.equals(password)) 
        {
            return Auth.IsAuth = true;
        }
        return Auth.IsAuth = false;
    }

    private static void Loading()
    {
        try 
        {
            System.err.print("Login");
            for (int i = 0; i < 5; i++) 
            {
                System.out.print('.');
                    Thread.sleep(150);
            }
            System.out.println();
        } 
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
