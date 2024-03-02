/*******************************************************

 * Program Name: ArrayList.h

 * Author: Lucas Gobaco

 * Date: 1 March 2024

 * Description: This program defines a class that manages an array list.

 *******************************************************/

#ifndef H_ARRAYLISTTYPE
#define H_ARRAYLISTTYPE

#include <iostream>

const int DEFAULT_ARRAY_SIZE = 100;

using namespace std;

template <typename T>
class ArrayList {
public:
    //Constructor
    //Creates an array of the size specified by the 
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0,
    //               and maxLength = size;
    ArrayList(int size = DEFAULT_ARRAY_SIZE);

    //Destructor
    //Deallocate the memory occupied by the array.
    virtual ~ArrayList();

    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty;
    //               otherwise, returns false.
    bool isEmpty() const;

    //Function to determine whether the list is full
    //Postcondition: Returns true if the list is full; 
    //               otherwise, returns false.
    bool isFull() const;

    //Function to determine the number of elements in 
    //the list.
    //Postcondition: Returns the value of length.
    int size() const;

    //Function to determine the maximum size of the list
    //Postcondition: Returns the value of maxLength.
    int maxSize() const;

    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
    //               standard output device.
    void print() const;

    //Function to determine whether item is the same as
    //the item in the list at the position specified 
    //by location.
    //Postcondition: Returns true if the list[location] 
    //               is the same as item; otherwise, 
    //               returns false.
    //               If location is out of range, an 
    //               appropriate message is displayed.
    bool equal(int location, const T& item) const;

    //Function to insert insertItem an item at the end of 
    //the list. Note that this is an abstract function.
    //Postcondition: list[length] = insertItem; and length++;
    //               If the list is full, an appropriate 
    //               message is displayed.
    virtual void insert(const T& insertItem) = 0;

    //Function to remove the item from the list at the 
    //position specified by location 
    //Postcondition: The list element at list[location] is 
    //               removed and length is decremented by 1.
    //               If location is out of range, an 
    //               appropriate message is displayed.
    void removeAt(int location);

    //Function to retrieve the element from the list at the  
    //position specified by location 
    //Postcondition: retItem = list[location] 
    //               If location is out of range, an 
    //               appropriate message is displayed.
    void retrieveAt(int location, T& retItem) const;

    //Function to replace repItem the elements in the list 
    //at the position specified by location. 
    //Note that this is an abstract function.
    //Postcondition: list[location] = repItem 
    //               If location is out of range, an 
    //               appropriate message is displayed.
    virtual void replaceAt(int location, const T& repItem) = 0;

    //Function to remove all the elements from the list 
    //After this operation, the size of the list is zero.
    //Postcondition: length = 0;
    void clear();

    //Function to search the list for searchItem.
    //Note that this is an abstract function.
    //Postcondition: If the item is found, returns the 
    //               location in the array where the item is  
    //               found; otherwise, returns -1.
    virtual int search(const T& searchItem) const = 0;

    //Function to remove removeItem from the list.
    //Note that this is an abstract function.
    //Postcondition: If removeItem is found in the list,
    //               it is removed from the list and length 
    //               is decremented by one.
    virtual void remove(const T& removeItem) = 0;

    template <typename T>
    void swap(int first, int second);
    template <typename T>
    int partition(int first, int last);
    void recQuickSort(int first, int last);
    template <typename T>
    void quickSort(int length);

    //Overloads the assignment operator
    const ArrayList<T>& operator=(const ArrayList<T>&);

protected:
    T* list;            //array to hold the list elements
    int length;         //variable to store the length of the list
    int maxLength;      //variable to store the maximum size of the list
};

#endif