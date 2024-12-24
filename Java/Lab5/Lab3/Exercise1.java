

import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collector;
import java.util.stream.Collectors;




public class Exercise1 {

   public static void main(String[] args) {
      CountryDao countryDao= InMemoryWorldDao.getInstance();

      // countryDao.findAllCountries().stream().forEach(countrie -> {
      //    Optional<City> city = countrie.getCities().stream().max(Comparator.comparingInt(City::getPopulation));
      //    if (!city.isEmpty()) {
      //       System.out.println("For countries: " + countrie.getName() + " Most population city is: " + city.get().getName() + " With : " + city.get().getPopulation() + " Population");
      //    }
      // });


      Map<String, City> highestPopulatedCities = countryDao.findAllCountries()
      .stream()
      .filter(country -> country.getCities() != null && !country.getCities().isEmpty())
      .collect(
         Collectors.toMap(
            Country::getName, 
            c -> c.getCities().stream()
            .max(Comparator.comparingInt(City::getPopulation))
            .orElse(null)));

      highestPopulatedCities.forEach((country, city) -> {
         System.out.println("Country: " + country + ", Highest-Populated City: " + city);
      });
   }

}