/*******************************************************

 * Program Name: selectionSort.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a class that provides selection sort functions.

 *******************************************************/

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <iomanip>

using namespace std;

/**
   Finds the index of the smallest element in a portion of an array.
   @param list the array with the elements to search
   @param first the index of the first element in the portion to search
   @param last the index of the last element in the portion to search
   @return the index of the smallest element in the portion of the array from first to last
*/
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
}

/**
   Swaps two elements in an array.
   @param list the array with the elements to swap
   @param first the index of the first element
   @param second the index of the second element
*/
template <typename T>
void swap(T list[], int first, int second) {
    T temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

/**
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
template <typename T>
void print(T a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


/**
   Sorts an array in ascending order using the selection sort algorithm.
   @param list the array to sort
   @param length the number of elements in list
*/
template <typename T>
void selectionSort(T list[], int length) {
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
}

#endif