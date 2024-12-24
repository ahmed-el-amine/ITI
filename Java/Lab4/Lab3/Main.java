import MyPackage.*;

public class Main {
    public static void main(String args[])
    {
        Complex<Double> x = new Complex<Double>(10.0, -20.0);
        Complex<Double> y = new Complex<Double>(5.0, 3.0);
        
        Complex<Double> newComplex = x.addition(y);

        x.display();
        y.display();
        newComplex.display();

    }    
}
