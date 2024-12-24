import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please Enter A String : ");
        String userInput = scanner.nextLine();

        scanner.close();

        boolean isAlpha = true;
        for (int i = 0; i < userInput.length(); i++) {
            if (!Character.isLetter(userInput.charAt(i))) {
                isAlpha = false;
                break;
            }
        }

        if (isAlpha) System.out.println("You Enterd String All Chars is alphabets");
        else System.out.println("You Enterd String Has Chars is not an alphabets");
    }
}