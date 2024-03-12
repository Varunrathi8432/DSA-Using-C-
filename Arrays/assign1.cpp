
#include <iostream>
using namespace std;

class Array
{
    int size;
    int lastindex;
    int *ptr;

public:
    // Constructor: Initialize the size, create dynamic array, and set the lastindex to -1
    Array(int size)
    {
        this->size = size;
        ptr = new int[size]; // Dynamically allocate an integer array of 'size'
        lastindex = -1;      // Initialize the lastindex to -1 as the array is empty initially
    }

    // Copy Constructor: Create a deep copy of the object
    Array(Array &obj)
    {
        size = obj.size;           // Copy the size
        lastindex = obj.lastindex; // Copy the lastindex
        ptr = new int[size];       // Create a new dynamic array
        for (int i = 0; i <= lastindex; i++)
        {
            ptr[i] = obj.ptr[i]; // Copy the elements from the source object
        }
    }

    // Destructor: Deallocate the dynamic array
    ~Array()
    {
        delete[] ptr; // Deallocate the memory to avoid memory leaks
    }

    // Check if the array is empty
    bool isempty()
    {
        if (lastindex == -1)
        {
            return true;
        }
        return false;
    }

    // Append an element to the end of the array
    void append(int data)
    {
        if (isFull())
        {
            return; // If the array is full, do nothing
        }
        ptr[lastindex + 1] = data; // Add 'data' to the next available index
        lastindex += 1;            // Increment the lastindex
    }

    // Insert an element at a specified index
    void insert(int index, int data)
    {
        if (index > lastindex + 1 || index < 0)
            return; // If the index is out of bounds, do nothing
        else if (isFull())
            return; // If the array is full, do nothing
        else
        {
            for (int i = lastindex; i >= index; i--)
            {
                ptr[i + 1] = ptr[i]; // Shift elements to make space for 'data'
            }
            ptr[index] = data; // Insert 'data' at the specified index
        }
        lastindex += 1; // Increment the lastindex
    }

    // Edit an element at a specified index
    void edit(int index, int data)
    {
        if (index < 0 || index > lastindex)
            cout << "\ninvalid index"; // If the index is out of bounds, display a message
        else
            ptr[index] = data; // Update the element at the specified index with 'data'
    }

    // Delete an element at a specified index
    void Delete(int index)
    {
        if (isempty() || index > lastindex)
            return; // If the array is empty or the index is out of bounds, do nothing
        for (int i = index; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1]; // Shift elements to fill the gap left by the deleted element
        }
        lastindex -= 1; // Decrement the lastindex
    }

    // Check if the array is full
    bool isFull()
    {
        if (lastindex + 1 == size)
            return true; // If the lastindex is equal to the size, the array is full
        return false;
    }

    // Get the element at a specified index
    int getdata(int index)
    {
        if (index < 0 || index > lastindex)
        {
            cout << "\n invalid index" << endl; // If the index is out of bounds, display a message
            throw new exception();              // Throw an exception to signal the error
        }
        return ptr[index]; // Return the element at the specified index
    }

    // Get the number of elements in the array
    int count()
    {
        return lastindex + 1; // The number of elements is equal to lastindex + 1
    }

    // Search for an element and return its index (or -1 if not found)
    int search(int data)
    {
        for (int i = 0; i <= lastindex; i++)
        {
            if (ptr[i] == data)
                return i; // If 'data' is found, return its index
        }
        return -1; // If 'data' is not found, return -1
    }

    // Display the elements of the array
    void display()
    {
        for (int i = 0; i <= lastindex; i++)
        {
            cout << ptr[i] << " "; // Display each element followed by a space
        }
        cout << endl; // Move to the next line after displaying all elements
    }
    // Assignment operator: Create a deep copy of the source object
    Array &operator=(Array &obj)
    {
        // Check if the assignment is not self-assignment
        if (this != &obj)
        {
            // Check if the current object has allocated memory
            if (ptr != nullptr)
                delete[] ptr; // Deallocate the current dynamic array

            size = obj.size;           // Copy the size from the source object
            lastindex = obj.lastindex; // Copy the lastindex from the source object
            ptr = new int[size];       // Create a new dynamic array

            for (int i = 0; i <= lastindex; i++)
            {
                ptr[i] = obj.ptr[i]; // Copy the elements from the source object to the current object
            }
        }
        return *this; // Return a reference to the current object
    }
};

int main()
{
    Array a1(8);
    a1.append(21);
    a1.append(34);
    a1.append(54);
    a1.append(87);
    a1.insert(1, 93);
    // a1.display();
    a1.Delete(2);
    // a1.display();
    a1.Delete(3);
    a1.display();
    // cout<<a1.count()<<endl;
    // cout<<a1.search(21)<<endl;
    // cout<<a1.getdata(1)<<endl;
    Array a2(8);
    a2 = a1;
    a2.display();
    return 0;
}