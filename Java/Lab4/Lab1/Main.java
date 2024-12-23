import MyPackage.MyException;
import MyPackage.MyTest;

public class Main {
    public static void main(String args[])
    {
        try {
            MyTest.TestMyCode();
        } catch (MyException e) {
            e.printStackTrace();
        }
    }
}
