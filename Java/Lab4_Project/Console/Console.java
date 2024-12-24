package Console;

public class Console {
    public static void ClearConsole()
    {
        try 
        {
            System.out.print("\033[H\033[2J");
            System.out.flush();
        } 
        catch (Exception e) {
        }

        //  try {
        //     if (System.getProperty("os.name").contains("Windows")) {
        //         new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        //     } else {
        //         new ProcessBuilder("clear").inheritIO().start().waitFor();
        //     }
        // } catch (IOException | InterruptedException e) {
        //     e.printStackTrace();
        // }

        // try
        // {
        //     final String os = System.getProperty("os.name");
            
        //     if (os.contains("Windows"))
        //     {
        //         Runtime.getRuntime().exec("cls");
        //     }
        //     else
        //     {
        //         Runtime.getRuntime().exec("clear");
        //     }
        // }
        // catch (final Exception e)
        // {
        // }
    }
}
