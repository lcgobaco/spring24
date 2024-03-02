/*******************************************************

 * Program Name: ArrayList.cpp

 * Author: Lucas Gobaco

 * Date: 14 February 2024

 * Description: This program defines a class that manages an array list.

 *******************************************************/

#include <iostream>

using namespace std;

template <typename T>
class ArrayList {
public:
    //Constructor
    //Creates an array of the size specified by the 
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0,
    //               and maxSize = size;
    ArrayList(int size = 100);


    //Destructor
    //Deallocate the memory occupied by the array.
    ~ArrayList();

    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty;
    //               otherwise, returns false.
    bool isEmpty() const;

    //Function to determine whether the list is full
    //Postcondition: Returns true if the list is full; 
    //               otherwise, returns false.
    bool isFull() const;

    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
    //               standard output device.
    void print() const;


    //Function to insert insertItem an item at the end of 
    //the list. Note that this is an abstract function.
    //Postcondition: list[length] = insertItem; and length++;
    //               If the list is full, an appropriate 
    //               message is displayed.
    virtual void insert(const T& insertItem);

    //Function to retrieve the element from the list at the  
    //position specified by location 
    //Postcondition: retItem = list[location] 
    //               If location is out of range, an 
    //               appropriate message is displayed.
    void retrieve(int location, T& retItem) const;

    //Function to search the list for searchItem.
    //Note that this is an abstract function.
    //Postcondition: If the item is found, returns the 
    //               location in the array where the item is  
    //               found; otherwise, returns -1.
    virtual int search(const T& searchItem);

    //Function to remove removeItem from the list.
    //Note that this is an abstract function.
    //Postcondition: If removeItem is found in the list,
    //               it is removed from the list and length 
    //               is decremented by one.
    virtual void remove(const T& removeItem);

protected:
    T* list; //array to hold the list elements
    int length;     //variable to store the length of the list
    int maxSize;    //variable to store the maximum 
    //size of the list
};

template <typename T>
ArrayList<T>::ArrayList(int size) {
    list = new T[size];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    for (for int i = 0; i < length; i++) {
        delete T;
    }
    delete list;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    if (list != nullptr) {
        if (length == 0) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    if (list != nullptr) {
        if (length == maxSize) {
            return true;
        }
    }
    return false;
}

template <typename T>
void ArrayList<T>::print() const {
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <typename T>
void ArrayList<T>::insert(const T& insertItem) {
    if (isFull()) {
        cout << "The list is full" << endl;
    }
    else {
        list[length] = insertItem;
        length++;
    }
}

template <typename T>
void ArrayList<T>::retrieve(int location, T& retItem) const {
    if (location < 0 || location >= length) {
        cout << "The location of the item to be retrieved is out of range" << endl;
    }
    else {
        retItem = list[location];
    }
}

template <typename T>
int ArrayList<T>::search(const T& searchItem) {
    for (int i = 0; i < length; i++) {
        if (list[i] == searchItem) {
            return i;
        }
    }
    return -1;
}