package MyPackage;

public class MyTest {
    public static void TestMyCode() throws MyException
    {
        MyClass.divideTwoNumbers(10, 0);

        int[] myArr = {1,2,3,45};
        MyClass.elementAt(myArr, 10);

        MyClass.sumTwoNumbers(0, 0);
    }
}
