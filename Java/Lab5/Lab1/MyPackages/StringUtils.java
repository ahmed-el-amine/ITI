package MyPackages;

public class StringUtils {
    public static String betterString(String s1, String s2, BetterStringChecker checker) {
        return checker.isBetter(s1, s2) ? s1 : s2;
    }
}
