import MyPackages.StringUtils;

public class Main {
    public static void main(String[] args) {
        String string1 = "Ahmed";
        String string2 = "Mohamed";
        
        String longer = StringUtils.betterString(string1, string2, (s1, s2) -> s1.length() > s2.length());
        System.out.println("Longer String: " + longer);
        
        String first = StringUtils.betterString(string1, string2, (s1, s2) -> true);
        System.out.println("First String: " + first);
    }
}
