

import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.function.BiConsumer;
import java.util.stream.Collector;
import java.util.stream.Collectors;



public class Exercise2 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        
        countryDao.getAllContinents().stream().forEach(continentName -> 
        {
            Map<String, City> e = countryDao.findCountriesByContinent(continentName).stream()
            .filter(x -> x.getCities() != null && !x.getCities().isEmpty())
            .collect(
                Collectors.toMap(Country::getName, x -> x.getCities().stream()
                .filter(country -> x.getCities() != null && !x.getCities().isEmpty())
                .max(Comparator.comparingInt(City::getPopulation)).orElse(null)));
        
                
            e.forEach((country, city) -> {
                System.out.println("Country: " + country + ", Highest-Populated City: " + city);
             });
             System.out.println("---------------------------------");
        });

        // Afric
        // countryDao.getAllContinents().stream().forEach(continentName -> 
        // {
        //     // Egypt
        //     countryDao.findCountriesByContinent(continentName).stream().forEach(countrie -> {
                
        //         // Cairo
        //         Optional<City> city = countrie.getCities().stream().max(Comparator.comparingInt(City::getPopulation));
        //         if (!city.isEmpty()) {
        //            System.out.println("For countries: " + countrie.getName() + " Most population city is: " + city.get().getName() + " With : " + city.get().getPopulation() + " Population");
        //         }

        //     });
        // });

            // countryDao.getAllContinents().stream().forEach(continent -> {
                
            // });

    }

}
