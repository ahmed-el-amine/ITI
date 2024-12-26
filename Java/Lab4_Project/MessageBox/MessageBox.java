package MessageBox;

import ConsoleLib.ConsoleColors;

public class MessageBox {
    public static void showMessage(String message, MessageBoxType messageType)
    {
        System.out.println(ConsoleColors.RESET);
        System.out.print("=".repeat(message.length() / 2));

        setColorByType(messageType, true);

        System.out.print(messageType.toString());

        System.out.print(ConsoleColors.RESET);

        System.out.println("=".repeat(message.length() / 2));
        System.err.print("  ");

        setColorByType(messageType, false);
        System.out.print(message + ConsoleColors.RESET);

        System.err.println("  ");
        System.out.println("=".repeat(message.length() + (messageType.toString().length())));
    }

    private static void setColorByType(MessageBoxType messageType, boolean asBackGround)
    {
        switch (messageType) {
            case Successful:
                System.out.print(asBackGround ? ConsoleColors.GREEN_BACKGROUND : ConsoleColors.GREEN);
                break;
            case Error:
                System.out.print(asBackGround ? ConsoleColors.RED_BACKGROUND : ConsoleColors.RED);
                break;
                case Warning:
                System.out.print(asBackGround ? ConsoleColors.YELLOW_BACKGROUND : ConsoleColors.YELLOW);
                break;
                default:
                System.out.print(asBackGround ? ConsoleColors.CYAN_BACKGROUND : ConsoleColors.CYAN);
                break;
        }
    }
}
