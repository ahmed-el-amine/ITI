import MyPackage.*;

class MyClass implements MyInterface
{
//    public int age = 10;
}

public class main {
    public static void main(String[] args)
    {
        MyClass s = new MyClass();
        // s.age = 50;
        // MyClass.age = 10;

        if (MyClass.age == 10) {
            System.out.println("ASDASDASDASD");
        }

        double celsius = 25.6;
        Temperature t = new Temperature();
        double fahrenheit = t.apply(celsius);
        System.out.println(celsius + "°C is " + fahrenheit + "°F");
        
        Double[] data = {1.0, -3.0, 2.0};

        try {
            double root1 = QuadraticEquation.calc(data, false);
            double root2 = QuadraticEquation.calc(data, true);

            System.out.println("Root 1: " + root1);
            System.out.println("Root 2: " + root2);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
