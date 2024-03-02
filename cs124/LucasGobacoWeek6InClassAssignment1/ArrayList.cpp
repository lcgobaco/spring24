/*******************************************************

 * Program Name: ArrayList.cpp

 * Author: Lucas Gobaco

 * Date: 1 March 2024

 * Description: This program implements a class that manages an array list.

 *******************************************************/

#include "ArrayList.h"

using namespace std;

template <typename T>
ArrayList<T>::ArrayList(int size) {
    if (size <= 0) {
        cout << "The array size must be positive. Creating "
            << "an array of the size 100. " << endl;
        maxLength = DEFAULT_ARRAY_SIZE;
    }
    else
        maxLength = size;

    length = 0;

    list = new T[maxLength];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] list;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return (length == 0);
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return (length == maxLength);
}

template <typename T>
int ArrayList<T>::size() const {
    return length;
}

template <typename T>
int ArrayList<T>::maxSize() const {
    return maxLength;
}

template <typename T>
void ArrayList<T>::print() const {
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <typename T>
bool ArrayList<T>::equal(int location, const T& item)  const {
    if (location < 0 || location >= length) {
        cout << "The location of the item to be removed "
            << "is out of range." << endl;
        return false;
    }
    else
        return (list[location] == item);
}

template <typename T>
void ArrayList<T>::removeAt(int location) {
    if (location < 0 || location >= length) {
        cout << "The location of the item to be removed "
            << "is out of range." << endl;
    }
    else {
        for (int i = location; i < length - 1; i++) {
            list[i] = list[i + 1];
        }

        length--;
    }
} //end removeAt

template <typename T>
void ArrayList<T>::retrieveAt(int location, T& retItem) const {
    if (location < 0 || location >= length) {
        cout << "The location of the item to be retrieved is "
                << "out of range" << endl;
    }
    else
        retItem = list[location];
} //end retrieveAt

template <typename T>
void ArrayList<T>::clear() {
    length = 0;
} //end clear

template <typename T>
const ArrayList<T>& ArrayList<T>::operator= (const ArrayList<T>& otherList) {
    if (this != &otherList) {   //avoid self-assignment
        delete[] list;
        maxLength = otherList.maxLength;
        length = otherList.length;

        list = new T[maxLength];

        for (int i = 0; i < length; i++) {
            list[i] = otherList.list[i];
        }
    }
    return *this;
}

template <typename T>
void ArrayList<T>::swap(int first, int second) {
    T temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <typename T>
int ArrayList<T>::partition(int first, int last) {
    T pivot;

    int index, smallIndex;

    swap(first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }

    swap(first, smallIndex);

    return smallIndex;
} //end partition

void ArrayList<T>::recQuickSort(int first, int last) {
    int pivotLocation;

    if (first < last) {
        pivotLocation = partition(first, last);
        recQuickSort(first, pivotLocation - 1);
        recQuickSort(pivotLocation + 1, last);
    }
} //end recQuickSort

template <typename T>
void ArrayList<T>::quickSort(int length) {
    recQuickSort(0, length - 1);
} //end quickSort
