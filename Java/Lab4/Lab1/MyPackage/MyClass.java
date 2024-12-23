package MyPackage;

public class MyClass {
    public static int sumTwoNumbers(int x, int y) throws MyException
    {
        if (x < 0 || y < 0) throw new MyException("x or y cannot be zero");
        return x * y;
    }

    public static double divideTwoNumbers(double x, double y) throws MyException
    {
        if (y == 0) throw new MyException("can't divide by zero");
        return x / y;
    }

    public static int elementAt(int[] arr, int index) throws MyException
    {
        if (index < 0 || index >= arr.length) throw new MyException("Index " + index + " is OutOfRange [" + arr.length + "]");
        return arr[index];
    }
}

