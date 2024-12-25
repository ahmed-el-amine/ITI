

import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.function.BiConsumer;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;



public class Exercise2 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();

        // Continents[Africa, Asia, ...]
        List<City> listOfCities = countryDao.getAllContinents().stream()
            // Continent(Africa) => Countries[Egypt, Sudan]
            .map(continentName -> countryDao.findCountriesByContinent(continentName).stream()
            // Continent(Africa) => Countries(Egypt) => Cities[Cairo, Giza, ...]
            .map(country -> country.getCities())
            // Continent(Africa) => Countries(Egypt) => Cities[Cairo, Giza, ...] => Citie (get max Population Citie in Cities[])
            // This Will return An Array Has Only One Element The Max Citie Population
            .map(cities -> cities.stream().max(Comparator.comparingInt(City::getPopulation)))
            // Last max Returns Optional<City> we need to make soure that element isPresent using filter
            // this will return elements if not equal to null 
            .filter(Optional::isPresent)
            // After Filter We Will have an array of One Element That is Max Citie Population
            .map(city -> city.get()))

        // Returns List<List<Cities>> -> List<Cities>
        .map(streamCities -> streamCities.collect(Collectors.toList()))
        // Get Max  Population citie of Continents
        .map(cities -> cities.stream().max(Comparator.comparingInt(City::getPopulation)))
        // Last max Returns Optional<City> we need to make soure that element isPresent using filter
        // this will return elements if not equal to null 
        .filter(Optional::isPresent)
        .map(city -> city.get())
        // return all resutl as list
        .collect(Collectors.toList());

        listOfCities.forEach(x -> System.out.println(x));
    }

}
