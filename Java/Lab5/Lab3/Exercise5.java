



import java.util.Objects;
import java.util.Optional;
import java.util.stream.Collectors;

import static java.lang.System.out;
import static java.util.Comparator.comparing;
import static java.util.stream.Collectors.maxBy;

import java.util.Collection;

public class Exercise5 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        CityDao cityDao = InMemoryWorldDao.getInstance();

        // 
        countryDao.findAllCountries().stream()
        .map(country -> {
            return country.getCities().stream().filter(city -> city.getId() == country.getCapital());
        })
        // .collect(Collectors.tom)
        .forEach(x -> {
            x.forEach(m -> {
                System.out.println(m);
            });
        });
        
        ;
       //write your answer here 
    }

}