#include <iostream>
#include "SortClass.cpp"

using namespace std;

int main()
{
    int arr[] = {3, 2, 5, 3, 9, 1, 6, 99, 50, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "----------Quick Sort----------" << endl;
    cout << "Before ";
    SortClass::printArray(arr, size);

    SortClass::quickSort(arr, size);

    cout << "After  ";
    SortClass::printArray(arr, size);

    cout << endl;

    // --------------------------------------

    int arr2[] = {3, 2, 5, 3, 9, 1, 6, 99, 50, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "----------Bubble Sort----------" << endl;
    cout << "Before ";
    SortClass::printArray(arr2, size2);

    SortClass::bubbleSort(arr2, size2);

    cout << "After  ";
    SortClass::printArray(arr2, size2);

    cout << endl;

    // --------------------------------------

    int arr3[] = {60, 35, 25, 85, 65, 15, 50, 10, 20, 55};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "----------Selection Sort----------" << endl;
    cout << "Before ";
    SortClass::printArray(arr3, size3);

    SortClass::selectionSort(arr3, size3);

    cout << "After  ";
    SortClass::printArray(arr3, size3);

    cout << endl;

    // --------------------------------------

    // int arr4[] = {60, 35, 25, 85, 65};
    // const int size4 = sizeof(arr4) / sizeof(arr4[0]);

    // int newArr[size4];

    // cout << "----------Merge Sort----------" << endl;

    // SortClass::merageSort(arr4, size4, arr5, size5, newArr);

    // cout << "After   ";
    // SortClass::printArray(arr4, size4);
    // cout << "\t";
    // SortClass::printArray(arr5, size5);

    // SortClass::printArray(newArr, newArrSize);

    // cout << endl;

    // int arr[] = { 3, 2, 5, 3, 9, 1, 6, 99, 50, 4 };
    // int arr[] = { 60, 50, 10, 20 };
    // int arr[] = { 60, 50, 10, 20 };
    // int size = sizeof(arr) / sizeof(arr[0]);

    // SortClass::printArray(arr, size);

    // SortClass::bubbleSort(arr, size);
    // SortClass::selectionSort(arr, size);

    // SortClass::printArray(arr, size);

    return 0;
}