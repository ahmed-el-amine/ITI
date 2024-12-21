#include <iostream>

using namespace std;

class SortClass
{
    static void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

public:
    static void bubbleSort(int arr[], const int size)
    {
        int isSorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    isSorted = false;
                }
            }

            // if first loop finish without any swap then array is sorted
            // then exit from the function
            if (isSorted)
                return;
        }
    }

    static void selectionSort(int arr[], const int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < size; j++)
            {
                if (arr[minIndex] > arr[j])
                {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    static void insertionSort(int arr[], const int size)
    {
    }

    static void merageSort(int arr1[], const int size1, int arr2[], const int size2, int newArr[])
    {
        // int i = 0;
        // int j = 0;
        // int newArrIndex = 0;

        // while (i < size1 && j < size2)
        // {
        //     if (arr1[i] <= arr2[j])
        //     {
        //         newArr[newArrIndex++] = arr1[i++];
        //     }
        //     else
        //     {
        //         newArr[newArrIndex++] = arr2[j++];
        //     }
        // }

        // while (i < size1)
        // {
        //     newArr[newArrIndex++] = arr1[i++];
        // }

        // while (j < size2)
        // {
        //     newArr[newArrIndex++] = arr2[j++];
        // }
    }

    static void quickSort(int arr[], const int size)
    {
        if (size <= 1)
            return;

        int base = arr[0];

        int *leftArr = new int[size];
        int leftArrCount = 0;

        int *rightArr = new int[size];
        int rightArrCount = 0;

        for (int i = 1; i < size; i++)
        {
            if (arr[i] <= base)
            {
                leftArr[leftArrCount++] = arr[i];
            }
            else
            {
                rightArr[rightArrCount++] = arr[i];
            }
        }

        quickSort(leftArr, leftArrCount);
        quickSort(rightArr, rightArrCount);

        int index = 0;
        for (int i = 0; i < leftArrCount; i++)
        {
            arr[index++] = leftArr[i];
        }
        arr[index++] = base;
        for (int i = 0; i < rightArrCount; i++)
        {
            arr[index++] = rightArr[i];
        }

        delete[] leftArr;
        delete[] rightArr;
    }

    static void printArray(int arr[], const int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};