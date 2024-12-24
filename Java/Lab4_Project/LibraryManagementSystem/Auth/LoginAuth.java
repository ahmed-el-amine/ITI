package LibraryManagementSystem.Auth;

public class LoginAuth {
    private static final String username = "admin";
    private static final String password = "admin";

    public static boolean Login(String username, String password)
    {
        if (LoginAuth.username.equals(username) && LoginAuth.password.equals(password)) 
        {
            return Auth.IsAuth = true;
        }
        return Auth.IsAuth = false;
    }
}
