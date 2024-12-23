package MyPackage;
import java.util.function.*;

public class QuadraticEquation {
    static class QuadraticRootCalculator implements BiFunction<Double[], Boolean, Double> {
        @Override
        public Double apply(Double[] coefficients, Boolean positiveRoot) {
            double a = coefficients[0];
            double b = coefficients[1];
            double c = coefficients[2];

            double sqrtDiscriminant = Math.sqrt(Math.pow(b, 2) - 4 * a * c);
            return positiveRoot
                    ? (-b + sqrtDiscriminant) / (2 * a)
                    : (-b - sqrtDiscriminant) / (2 * a);
        }
    }

     public static Double calc(Double[] data, Boolean b) {
        BiFunction<Double[], Boolean, Double> calculateRoot = new QuadraticRootCalculator();

        return calculateRoot.apply(data, b);
    }
}
