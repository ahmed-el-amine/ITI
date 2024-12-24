package Validation;

public class Validation {
    public static boolean isValidInt(String value)
    {
        try {
            Integer.parseInt(value);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}
