
public class MinMax {
    public static void main(String args[]) 
    {
        int[] arr = new int[1000];
    
        // fill array
        for (int i = 0; i < 1000; i++)
        {
            arr[i] = i+1;
        }

        BinarySearchLib.BinarySearchReturnValue binarySearch = BinarySearchLib.BinarySearch(arr, 20);

        System.out.println(String.format("Value Is [%s] Index Is [%s] Time [%s]", binarySearch.getValue(), binarySearch.getIndex(), binarySearch.getEstimatedTime()));

    }
}


class BinarySearchLib
{
    public static class BinarySearchReturnValue {
        public int value;
        public int index;
        public long estimatedTime;

        public BinarySearchReturnValue(int value, int index, long estimatedTime)
        {
            this.value  = value;
            this.index = index;
            this.estimatedTime = estimatedTime;
        }

        public int getValue()
        {
            return value;
        }

        public int getIndex()
        {
            return index;
        }

        public long getEstimatedTime()
        {
            return estimatedTime;
        }
    }

    public static BinarySearchReturnValue BinarySearch(int[] arr, int value)
    {
        int index = -1;
        long startTime = System.nanoTime();


        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == value) {
                index = mid;
                break;
            } else if (arr[mid] < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }


        long estimatedTime = System.nanoTime() - startTime;

        BinarySearchReturnValue result = new BinarySearchReturnValue(value, index, estimatedTime);
        
        return result;
    }
}


