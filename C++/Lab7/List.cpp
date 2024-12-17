#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @class List
 * @brief A generic dynamic array-based list implementation with various utility methods.
 *
 * @tparam T The type of elements to store in the list.
 */

template <typename T>
class List
{
private:
    int index = -1;     ///< Tracks the current last index in the list.
    T *data = new T[0]; ///< Pointer to the dynamically allocated array holding the list elements.

    /**
     * @brief Copies the current data array to a new array.
     *
     * @param newData Pointer to the new array where data will be copied.
     */
    void copyToNew(T *newData)
    {
        for (int i = 0; i < this->index; i++)
        {
            newData[i] = this->data[i];
        }
    }

public:
    static int IntCount; ///< Tracks the number of List instances created.

    /**
     * @brief Default constructor. Initializes an empty list.
     */
    List()
    {
        List::IntCount++;
        cout << "Created " << List::IntCount << endl;
    }

    /**
     * @brief Copy constructor. Creates a deep copy of another List instance.
     *
     * @param old The List instance to copy from.
     */
    List(const List &old)
    {
        delete[] this->data;

        this->index = old.index;
        this->data = new T[this->index + 1];

        for (int i = 0; i <= this->index; i++)
        {
            this->data[i] = old.data[i];
        }

        List::IntCount++;
        cout << "Created " << List::IntCount << endl;
    }

    /**
     * @brief Adds a new element to the end of the list.
     *
     * @param value The element to add.
     */
    void Push(T value)
    {
        this->index++;
        T *newData = new T[this->index + 1];

        copyToNew(newData);

        newData[this->index] = value;

        delete[] this->data;
        this->data = newData;
    }

    /**
     * @brief Removes the last element from the list.
     */
    void Pop()
    {
        if (this->index <= -1)
            return;

        this->index--;
        T *newData = new T[this->index <= -1 ? 0 : this->index];

        copyToNew(newData);

        delete[] this->data;
        this->data = newData;
    }

    /**
     * @brief Appends an array of elements to the list.
     *
     * @param array The array of elements to add.
     * @param size The number of elements in the array.
     */
    void AddRange(T *array, int size)
    {
        this->index += size;
        T *newData = new T[this->index + 1];

        copyToNew(newData);

        for (int i = 0; i < size; i++)
        {
            newData[this->index - size + i + 1] = array[i];
        }

        delete[] this->data;
        this->data = newData;
    }

    /**
     * @brief Inserts an element at a specific position in the list.
     *
     * @param posation The zero-based index where the element should be inserted.
     * @param value The element to insert.
     * @throws std::out_of_range If the position is invalid.
     */
    void Insert(int posation, T value)
    {
        if (posation > this->index)
        {
            throw std::out_of_range("Position " + to_string(posation) + " is out of range. Valid range is 0 to " + to_string(this->index) + ".");
        }

        this->index++;
        T *newData = new T[this->index + 1];
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

    /**
     * @brief Removes the element at a specific position in the list.
     *
     * @param posation The zero-based index of the element to remove.
     */
    void RemoveAt(int posation)
    {
        if (this->index <= -1)
            return;

        if (posation > this->index)
            return;

        this->index--;
        T *newData = new T[this->index + 1];

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

    /**
     * @brief Retrieves the element at a specific position.
     *
     * @param posation The zero-based index of the element to retrieve.
     * @return The element at the specified position.
     * @throws std::out_of_range If the position is invalid.
     */
    T ElementAt(int posation)
    {
        if (this->index <= -1 || posation > this->index)
        {
            throw std::out_of_range("Position " + to_string(posation) + " is out of range.");
        }

        return this->data[posation];
    }

    /**
     * @brief Returns the number of elements in the list.
     *
     * @return The size of the list.
     */
    int Count()
    {
        return this->index + 1;
    }

    /**
     * @brief Removes all elements from the list.
     */
    void Clear()
    {
        this->index = -1;
        delete[] this->data;
        this->data = new T[0];
    }

    /**
     * @brief Retrieves a pointer to the internal array of the list.
     *
     * @return Pointer to the internal array.
     */
    T *getData()
    {
        return this->data;
    }

    /**
     * @brief Creates and returns a deep copy of the list.
     *
     * @return A new List instance containing the same elements as the original list.
     */
    List getDeepCopy()
    {
        List newList;

        for (int i = 0; i < this->Count(); i++)
        {
            newList.Push(this->data[i]);
        }

        return newList;
    }

    /**
     * @brief Overloaded '+' operator to add a new element to the list.
     *
     * @param value The element to add.
     */
    void operator+(T value)
    {
        this->Push(value);
    }

    /**
     * @brief Compares two lists for equality.
     *
     * @param c The list to compare with.
     * @return True if both lists contain the same elements in the same order; otherwise, false.
     */
    bool operator==(List &c)
    {
        if (this->Count() != c.Count())
            return false;

        T *data2 = c.getData();
        for (int i = 0; i < this->Count(); i++)
        {
            if (this->data[i] != data2[i])
                return false;
        }
        return true;
    }

    /**
     * @brief Compares the size of two lists.
     *
     * @param c The list to compare with.
     * @return True if this list is larger; otherwise, false.
     */
    bool operator>(List &c)
    {
        return this->Count() > c.Count();
    }

    /**
     * @brief Compares the size of two lists.
     *
     * @param c The list to compare with.
     * @return True if this list is larger or equal in size; otherwise, false.
     */
    bool operator>=(List &c)
    {
        return this->Count() >= c.Count();
    }

    /**
     * @brief Destructor. Cleans up dynamically allocated memory.
     */
    ~List()
    {
        List::IntCount--;
        cout << "Deleted " << List::IntCount << endl;
        delete[] data;
    }
};

template <typename T>
int List<T>::IntCount = 0;