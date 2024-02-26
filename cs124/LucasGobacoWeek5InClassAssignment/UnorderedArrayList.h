/*******************************************************

 * Program Name: UnorderedArrayList.h

 * Author: Lucas Gobaco

 * Date: 23 February 2024

 * Description: This program defines a class that manages an unordered array list.

 *******************************************************/

#ifndef H_UNORDEREDARRAYLISTTYPE
#define H_UNORDEREDARRAYLISTTYPE

#include <iostream>
#include "ArrayList.h"

using namespace std;

template <typename T>
class UnorderedArrayList : public ArrayList<T> {
public:
    //Constructor
    UnorderedArrayList();
    UnorderedArrayList(int size = DEFAULT_ARRAY_SIZE);

    void insert(const T& insertItem);
    void replaceAt(int location, const T& repItem);
    void remove(const T& removeItem);
    int search(const T& searchItem) const;    
};

template <typename T>
UnorderedArrayList<T>::UnorderedArrayList()
    : ArrayList<T>(DEFAULT_ARRAY_SIZE) {
    // TODO
}

template <typename T>
UnorderedArrayList<T>::UnorderedArrayList(int size)
    : ArrayList<T>(size) {
    // TODO
}  //end constructor

template <typename T>
void UnorderedArrayList<T>::insert(const T& insertItem) {
    if (this->length >= this->maxLength) { //the list is full
        cout << "Cannot insert in a full list." << endl;
    } else {
        this->list[this->length] = insertItem; //insert the item at the end
        this->length++; //increment the length
    }
} //end insertEnd

template <typename T>
int UnorderedArrayList<T>::search(const T& searchItem) const {
    int loc;
    bool found = false;
    loc = 0;

    while (loc < this->length && !found) {
        if (this->list[loc] == searchItem) {
            found = true;
        }
        else {
            loc++;
        }
    }

    if (found) {
        return loc;
    }
    else {
        return -1;
    }
} //end search

template <typename T>
void UnorderedArrayList<T>::remove(const T& removeItem) {
    int loc;

    if (this->length == 0) {
        cout << "Cannot delete from an empty list." << endl;
    } else {
        loc = search(removeItem);
        if (loc != -1) {
            this->removeAt(loc);
        }
        else {
            cout << "The tem to be deleted is not in the list." << endl;
        }
    }
} //end remove

template <typename T>
void UnorderedArrayList<T>::replaceAt(int location, const T& repItem) {
    if (location < 0 || location >= this->length) {
        cout << "The location of the item to be "
            << "replaced is out of range." << endl;
    }
    else {
        this->list[location] = repItem;
    }
} //end replaceAt

#endif