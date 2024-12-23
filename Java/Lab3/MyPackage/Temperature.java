package MyPackage;
import java.util.function.Function;

public class Temperature implements Function<Double, Double> {
    @Override
    public Double apply(Double celsius) {
        return (celsius * 9 / 5) + 32;
    }
    // static class CelsiusToFahrenheit implements Function<Double, Double> {
    //     @Override
    //     public Double apply(Double celsius) {
    //         return (celsius * 9 / 5) + 32;
    //     }
    // }

    // public static double convertCelsiusToFahrenheit(double celsius) {
    //     Function<Double, Double> celsiusToFahrenheit = new CelsiusToFahrenheit();
    //     return celsiusToFahrenheit.apply(celsius);
    // }
}
