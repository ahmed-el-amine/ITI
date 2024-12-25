package MyPackage;

import java.util.ArrayList;

public class TestCase {
    public static void TakeMyChildrens(ArrayList<? extends Shape> list)
    {
        for (int i = 0; i < list.size(); i++) {
            list.get(i).draw();
        }
    }
}
