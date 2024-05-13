/*******************************************************

 * Program Name: ArrayList.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: Header file for ArrayList class.

 *******************************************************/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept> // for std::out_of_range

template <typename T>
class ArrayList {
public:
    // Constructor
    ArrayList();

    // Destructor
    ~ArrayList();

    // Adds an element to the end of the ArrayList
    void add(const T& element);

    // Retrieves the element at the specified index in the ArrayList
    T& get(int index);

    // Sets the value of the element at the specified index in the ArrayList
    void set(int index, const T& element);

    // Returns the number of elements in the ArrayList
    int size() const;

    // Removes all elements from the ArrayList
    void clear();

    // Overloads the subscript operator [] to provide array-like access to elements in the ArrayList
    T& operator[](int index);

    // Removes the element at the specified index from the ArrayList
    void remove(int index);

private:
    // Initial capacity of the ArrayList
    static const int INITIAL_CAPACITY = 10;

    // Array to store elements
    T* elements;

    // Current capacity of the ArrayList
    int capacity;

    // Number of elements in the ArrayList
    int array_size;

    // Resizes the array when it's full
    void resize();
};

#include "ArrayList.cpp" // Include the implementation file because it's a template class

#endif // ARRAYLIST_H
