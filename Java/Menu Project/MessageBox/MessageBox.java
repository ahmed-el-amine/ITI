package MessageBox;

import ConsoleLib.ConsoleColors;

public class MessageBox {
    public static void showMessage(String messageTitle, String message, MessageBoxType messageType)
    {
        System.out.println(ConsoleColors.RESET);
        System.out.print("=".repeat(message.length() / 2));

        setColorByType(messageType, true);

        System.out.print(messageTitle.toString());

        System.out.print(ConsoleColors.RESET);

        System.out.println("=".repeat(message.length() / 2));

        setColorByType(messageType, false);
        System.out.println(message + ConsoleColors.RESET);

        System.out.println("=".repeat(message.length() + (messageTitle.toString().length())));
    }

    private static void setColorByType(MessageBoxType messageType, boolean asBackGround)
    {
        switch (messageType) {
            case Successful:
                System.out.print(asBackGround ? ConsoleColors.GREEN_UNDERLINED : ConsoleColors.GREEN);
                break;
            case Error:
                System.out.print(asBackGround ? ConsoleColors.RED_UNDERLINED : ConsoleColors.RED);
                break;
                case Warning:
                System.out.print(asBackGround ? ConsoleColors.YELLOW_UNDERLINED : ConsoleColors.YELLOW);
                break;
                default:
                System.out.print(asBackGround ? ConsoleColors.CYAN_UNDERLINED : ConsoleColors.CYAN);
                break;
        }
    }
}
