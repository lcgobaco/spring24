/*******************************************************

 * Program Name: ArrayList.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program defines a class manages an array list.

 *******************************************************/

#include "ArrayList.h" // Assuming ArrayList.h contains the definition of ArrayList
#include "Course.h"    // Assuming Course.h contains the definition of the Course class
#include "ComputerScienceTransferCourses.h" // Assuming ComputerScienceTransferCourses.h contains the definition of ComputerScienceTransferCourses

    // Constructor
template <class T>
ComputerScienceTransferCourses<T>::ComputerScienceTransferCourses() {}

    // Destructor
template <class T>
ComputerScienceTransferCourses<T>::~ComputerScienceTransferCourses() {}

    // Sort method using QuickSort algorithm
template <class T>
    void ComputerScienceTransferCourses<T>::sort() {
        quickSort(0, this->size() - 1);
    }

    // Helper function for QuickSort algorithm
template <class T>
    void ComputerScienceTransferCourses<T>::quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    // Helper function to partition the array for QuickSort
template <class T>
    int ComputerScienceTransferCourses<T>::partition(int low, int high) {
        Course pivot = this->get(high);
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (this->get(j).getCourseNumber() < pivot.getCourseNumber()) {
                i++;
                std::swap(this->get(i), this->get(j));
            }
        }

        std::swap(this->get(i + 1), this->get(high));
        return i + 1;
    }

    // Helper function for Binary Search algorithm
    template <class T>
    int ComputerScienceTransferCourses<T>::binarySearch(const Course& key, int low, int high) {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if (this->get(mid) == key)
                return mid;
            if (this->get(mid) > key)
                return binarySearch(key, low, mid - 1);
            return binarySearch(key, mid + 1, high);
        }
        return -1; // Element not found
    }
