package MyPackage.Dictionary;

import java.util.Map;
import java.util.TreeMap;

public class Dictionary {
    Map<Character, TreeMap<String, String>> dictionaryList = new TreeMap<>();

    public Dictionary()
    {
        this.LoadData();
    }

    public void PrintLetterValue(char key)
    {
        dictionaryList.get(key).entrySet().forEach(x -> {
            System.out.println(x.getValue());            
        });
    }

    public void PrintAll()
    {
        dictionaryList.entrySet().forEach(x -> 
        {
            System.out.println(x.getKey());
            System.out.println();
            
            x.getValue().entrySet().forEach(e -> {
                System.out.print(e.getKey() + " : ");
                System.out.println(e.getValue());
            });
            
            System.out.println();
            System.out.println("---------");
        });
    }

    private void LoadData()
    {
        for (char letter = 'a'; letter <= 'z'; letter++) {
            dictionaryList.put(letter, new TreeMap<>());
        }
        dictionaryList.get('a').put("apple", "A fruit that is sweet and crisp.");
        dictionaryList.get('a').put("ant", "A small insect that lives in colonies.");
        dictionaryList.get('a').put("arrow", "A projectile shot from a bow.");
        dictionaryList.get('b').put("banana", "A long, yellow fruit that is sweet.");
        dictionaryList.get('b').put("ball", "A round object used in games.");
        dictionaryList.get('b').put("butterfly", "An insect with colorful wings.");
        dictionaryList.get('c').put("cat", "A small domesticated carnivorous mammal.");
        dictionaryList.get('c').put("car", "A vehicle used for transportation.");
        dictionaryList.get('c').put("cake", "A sweet baked dessert.");
        dictionaryList.get('d').put("dog", "A domesticated carnivorous mammal, man's best friend.");
        dictionaryList.get('d').put("dolphin", "A highly intelligent aquatic mammal.");
        dictionaryList.get('d').put("drum", "A musical instrument played by beating.");
        dictionaryList.get('e').put("elephant", "A large herbivorous mammal with a trunk.");
        dictionaryList.get('e').put("egg", "An oval or round object laid by a female bird.");
        dictionaryList.get('e').put("engine", "A machine that converts energy into motion.");
        dictionaryList.get('f').put("fish", "A cold-blooded vertebrate living in water.");
        dictionaryList.get('f').put("frog", "An amphibian that hops and croaks.");
        dictionaryList.get('f').put("fan", "A device used to create airflow.");
        dictionaryList.get('g').put("grape", "A small, round, and juicy fruit.");
        dictionaryList.get('g').put("goat", "A domesticated animal raised for milk and meat.");
        dictionaryList.get('g').put("guitar", "A string instrument played by strumming.");
        dictionaryList.get('h').put("hat", "A head covering often worn for style or protection.");
        dictionaryList.get('h').put("horse", "A large, strong animal used for riding or farming.");
        dictionaryList.get('h').put("hammer", "A tool used to drive nails or break objects.");
        dictionaryList.get('i').put("ice", "Frozen water, a solid state of H2O.");
        dictionaryList.get('i').put("igloo", "A dome-shaped house made of ice blocks.");
        dictionaryList.get('i').put("iron", "A metal used for making tools and machinery.");
        dictionaryList.get('j').put("jelly", "A sweet, soft food made from fruit juice and gelatin.");
        dictionaryList.get('j').put("jacket", "A garment worn to keep warm.");
        dictionaryList.get('j').put("juice", "A liquid extracted from fruits or vegetables.");
    }
}
