#include <iostream>
using namespace std;


class BinarySearch
{
    int *arr;
    int size;

    public:
    enum State {
        Found = 1,
        NotFound = -1
    };
    struct Result
    {
        State State;
        int target;
        int index;
    };
    BinarySearch(int arr[], int size)
    {
        this->size = size;
        this->arr = new int[size]; 
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
    }

    Result SearchFor(int target)
    {
        Result r;
        r.target = target;
        r.index = -1;

        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int middleIndex = left + (right - left) / 2;

            if (arr[middleIndex] == target)
            {
                r.State = State::Found;
                r.index = middleIndex;
                return r;
            } 
            if (arr[middleIndex] < target) left = middleIndex + 1; 
            else right = middleIndex - 1;
        }

        return r;
    }

    ~BinarySearch() {
        delete[] arr;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    BinarySearch bs(arr, size);

    BinarySearch::Result r = bs.SearchFor(11);

    if (r.State == BinarySearch::Found)
    {
        cout << "Target " << r.target << " Exist In Index " << r.index;
    }
    else
    {
        cout << "Target " << r.target << " Not Exist";
    }
    

    return 0;
}