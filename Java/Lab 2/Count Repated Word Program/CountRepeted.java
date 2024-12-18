import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class CountRepeted {

    public static void main(String args[])
    {
        String sentence = "ITI develpos people and ITI house of developers and ITI for people";

        // First Way
        System.out.println("----------------With Split-----------------");
        int count = CountWordLib.SplitCount(sentence, "ITI");

        if (count == 0)  System.out.println("There Is No ITI In Sentence");
        else System.out.println("There Is Number " + (count) + " Of ITI Sentence");

        System.out.println("----------------MatchCount-----------------");
        int count2 = CountWordLib.MatchCount(sentence, "ITI");

        if (count2 == 0)  System.out.println("There Is No ITI In Sentence");
        else System.out.println("There Is Number " + (count2) + " Of ITI Sentence");


        System.out.println("----------------With StringTokenizer-----------------");
        int count3 = CountWordLib.TokinizerCount(sentence, "ITI");
        if (count3 == 0)  System.out.println("There Is No ITI In Sentence");
        else System.out.println("There Is Number " + (count3) + " Of ITI Sentence");
        
    }

}


class CountWordLib
{
    public static int SplitCount(String sentence, String word)
    {
        int count = 0;
        
        String[] parts = sentence.split(word);

        if (parts.length > 1)
        {
            count = parts.length - 1;
        }

        return count;
    }

    public static int MatchCount(String sentence, String word)
    {
        int count = 0;

        String regex = "\\b" + word + "\\b";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(sentence);

        while (matcher.find()) {
            count++;
        }

        return count;
    }

    public static int TokinizerCount(String sentence, String word)
    {
        int count = 0;

        StringTokenizer tokenizer =  new StringTokenizer(sentence, word);
        while (tokenizer.hasMoreTokens()) {
            count++;
            tokenizer.nextToken();
        }

        return count;
    }

}