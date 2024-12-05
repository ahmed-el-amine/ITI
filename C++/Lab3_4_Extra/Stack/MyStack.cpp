#include <iostream>
#include <stdexcept>

using namespace std;

class MyStack
{
private:
    int index = -1;
    int *data = new int[0];

    void copyToNew(int *newData)
    {
        // copy old data to the new array
        for (int i = 0; i < this->index; i++)
        {
            newData[i] = this->data[i];
        }
    }

public:
    /// @brief add value to the end of the list
    /// @param value
    void Push(int value)
    {
        this->index++;
        int *newData = new int[this->index + 1];

        copyToNew(newData);

        // push new array value
        newData[this->index] = value;

        delete[] this->data;
        this->data = newData;
    }

    /// @brief remove last element from list
    void Pop()
    {
        if (this->index <= -1)
            return;

        this->index--;
        int *newData = new int[this->index];

        copyToNew(newData);

        delete[] this->data;
        this->data = newData;
    }

    /// @brief this function takes two params first array of int sec the size of array and add this array to the end of list
    /// @param array
    /// @param size
    void AddRange(int *array, int size)
    {
        this->index += size;
        int *newData = new int[this->index + 1];

        copyToNew(newData);

        for (int i = 0; i < size; i++)
        {
            newData[this->index - size + i + 1] = array[i];
        }

        delete[] this->data;
        this->data = newData;
    }

    /// @brief this function takes two params first is the posation sec is the value to insert in that posation
    /// @brief return exception out_of_range if you insert out of range posation
    /// @param posation
    /// @param value
    void Insert(int posation, int value)
    {
        if (posation > this->index)
        {
            throw std::out_of_range("Posation " + to_string(posation) + " is out of range. Valid range is 0 to " + to_string(this->index) + ".");
        }

        this->index++;
        int *newData = new int[this->index + 1];
        bool isInserted = false;
        for (int i = 0; i <= this->index; i++)
        {
            if (i == posation)
            {
                newData[i] = value;
                isInserted = true;
            }
            else
            {
                newData[i] = this->data[isInserted ? i - 1 : i];
            }
        }

        delete[] this->data;
        this->data = newData;
    }

    /// @brief remove element at posation
    /// @param posation
    void RemoveAt(int posation)
    {
        if (this->index <= -1)
            return;

        if (posation > this->index)
            return;

        this->index--;
        int *newData = new int[this->index + 1];

        bool isRemoved = false;

        for (int i = 0; i <= this->index + 1; i++)
        {
            if (i == posation)
            {
                isRemoved = true;
            }
            else
            {
                newData[isRemoved ? i - 1 : i] = this->data[i];
            }
        }

        delete[] this->data;
        this->data = newData;
    }

    /// @brief this function return value at posation from list and throw out of range error if no posation found
    /// @param posation
    /// @return value in posation
    int ElementAt(int posation)
    {
        if (this->index <= -1 || posation > this->index)
        {
            throw std::out_of_range("There is no posation " + to_string(posation) + " is out of range.");
        }

        return this->data[posation];
    }

    /// @brief return list size/count
    /// @return
    int Count()
    {
        return this->index + 1;
    }

    /// @brief delete all list data
    void Clear()
    {
        this->index = -1;
        delete[] this->data;
        this->data = new int[0];
    }

    /// @brief return list data
    /// @return
    int *getData()
    {
        return this->data;
    }

    MyStack getDeepCopy()
    {
        MyStack newStack;

        for (int i = 0; i < this->Count(); i++)
        {
            newStack.Push(this->data[i]);
        }

        return newStack;
    }

    void operator+(int value)
    {
        this->Push(value);
    }

    bool operator==(MyStack c)
    {
        if (this->Count() != c.Count())
            return false;

        int *data2 = c.getData();
        for (int i = 0; i < this->Count(); i++)
        {
            if (this->data[i] != data2[i])
                return false;
        }
        return true;
    }

    bool operator>(MyStack c)
    {
        return this->Count() > c.Count();
    }

    bool operator>=(MyStack c)
    {
        return this->Count() >= c.Count();
    }

    ~MyStack()
    {
        delete[] data;
    }
};