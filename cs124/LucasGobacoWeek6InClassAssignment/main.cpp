/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 3 March 2024

 * Description: This program tests an implementation of the bubble sort algorithm using templates.

 *******************************************************/

#include <iostream>
#include <algorithm> // C++ library sort

const int ITERATIONS = 1000;
const int MAX_SIZE = 100000;

using namespace std;

template <typename T>
void swap(T list[], int first, int second);
template <typename T>
void bubbleSort(T list[], int length);
template <typename T>
void random_fill(T a[], int size);
template <typename T>
void print(T a[], int size);

int main() {
    int values[MAX_SIZE];
    int size = 0;

    cout << "Demo with " << size << " elements:" << endl;
    cout << "Enter array size: ";
    cin >> size;

    int before = time(0);
    srand(before);
    for (int i = 1; i <= ITERATIONS; i++) {
        random_fill(values, size);
        cout << "Before sort:" << endl;
        print(values, size);
        bubbleSort(values, size);
        print(values, size);
        cout << "After sort: " << values << endl;
    }
    int after = time(0);
    cout << "Elapsed time with bubble sort: "
        << (after - before) * 1.0 / ITERATIONS << " seconds" << endl;

    return 0;
}

/*
* Swaps two integer values
*/
template <typename T>
void swap(T list[], int first, int second) {
    T temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

/*
* Bubble sort
*/
template <typename T>
void bubbleSort(T list[], int length) {    
    for (int iteration = 1; iteration < length; iteration++) {
        for (int index = 0; index < length - iteration; index++) {            
            if (list[index] > list[index + 1]) {
                swap(list, index, index + 1);
            }
        }
    }
}

/**
 * Fill array with random numbers
 */
template <typename T>
void random_fill(T a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100;
    }
}

/**
 * Print out array
 */
template <typename T>
void print(T a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}