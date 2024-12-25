import MyPackage.Dictionary.Dictionary;

public class Main {

    public static void main(String[] args) {
        Dictionary d = new Dictionary();

        d.PrintLetterValue('a');
        d.PrintLetterValue('z');
        d.PrintAll();
    }
}