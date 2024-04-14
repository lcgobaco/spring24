#pragma once
#include <iomanip>

template <typename T>
int minLocation(T list[], int first, int last)
{
    int loc, minIndex;
    minIndex = first;

    for (loc = first + 1; loc <= last; loc++) {
        if (list[loc] < list[minIndex]) {
            minIndex = loc;
        }
    }

    return minIndex;
} //end minLocation

template <typename T>
void swap(T list[], int first, int second) {
    T temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

/**
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
template <typename T>
void print(T a[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void selectionSort(T list[], int length) {
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
} //end selectionSort