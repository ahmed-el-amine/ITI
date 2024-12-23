import java.util.ArrayList;
import MyPackage.*;

public class Main {
    public static void main(String[] args)
    {
        ArrayList<Shape> myCShapes = new ArrayList<Shape>();

        for (int i = 0; i < 3; i++) {
            myCShapes.add(new Circle());
        }
        for (int i = 0; i < 3; i++) {
            myCShapes.add(new Rectangle());
        }

        TestCase.TakeMyChildrens(myCShapes);
    }    
}
