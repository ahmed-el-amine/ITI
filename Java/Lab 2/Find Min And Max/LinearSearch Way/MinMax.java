import java.util.Random;

class MinMax {
    public static void main(String args[]) 
    {
        int[] arr = new int[1000];
        Random random = new Random();
        int min = 1;
        int max = 10000;

        // fill array
        for (int i = 0; i < 1000; i++)
        {
            int randomNum = random.nextInt(max - min + 1) + min;
            arr[i] = randomNum;
        }
        
        LinearSearch linearSearch = new LinearSearch(arr);

        System.out.println(String.format("Min Num [%s] Max Num [%s] Time [%s]", linearSearch.getMinValue(), linearSearch.getMaxValue(), linearSearch.getEstimatedTime()));
    }
}


class LinearSearch {
    private int minValue;
    private int maxValue;
    private long estimatedTime;

    public LinearSearch(int[] arr)
    {
        long startTime = System.nanoTime();
        
        for (int i = 0; i < arr.length; i++) {
            int x = arr[i];
            if (i != 0)
            {
                if (x < minValue) minValue = x;
                if (x > maxValue) maxValue = x;
            }
            else
            {
                minValue = x;
                maxValue = x;
            }
        }
        estimatedTime = System.nanoTime() - startTime;
    }

    public int getMinValue()
    {
        return minValue;
    }

    public int getMaxValue()
    {
        return maxValue;
    }

    public long getEstimatedTime()
    {
        return estimatedTime;
    }
}