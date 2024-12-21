#include <iostream>
using namespace std;


void linearSearch(int arr[], int size, int target)
{
    int existsIn[size];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            existsIn[count++] = i;
        }
    }
    if (count > 0) {
        cout << "Target [" << target << "] Exists In Array Count [" << count << "] Times Exists In ";
        for (int i = 0; i < count; i++)
        {
            cout << existsIn[i] << " ";
        }
        cout << endl;
    }   
    else cout << "Target Not Found In The Array"; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    linearSearch(arr, size, 4);
    return 0;
}
