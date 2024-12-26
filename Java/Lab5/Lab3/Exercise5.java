



import java.util.Objects;
import java.util.Optional;
import java.util.stream.Collectors;

import static java.lang.System.out;
import static java.util.Comparator.comparing;
import static java.util.stream.Collectors.maxBy;

import java.util.Collection;
import java.util.Comparator;

public class Exercise5 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        CityDao cityDao = InMemoryWorldDao.getInstance();
       
        Optional<City> maxCapital = // 
        countryDao.findAllCountries().stream()
       .flatMap(country -> {
           return country.getCities().stream().filter(city -> city.getId() == country.getCapital()).findFirst().stream();
       })
       .max(Comparator.comparingInt(City::getPopulation));

       System.out.println(maxCapital.isPresent() ? maxCapital.get() : "Cannot found any max country");

       ////////////////////////////////////////////////
        // Optional<City> maxCapital = countryDao.findAllCountries().stream()
        // .flatMap(country -> {
        //     return country.getCities().stream().filter(city -> city.getId() == country.getCapital()).findFirst().stream();
        // })
        // .max(Comparator.comparingInt(City::getPopulation));

        // System.out.println(maxCapital.isPresent() ? maxCapital.get() : "Cannot found any max country");
        
    }

}