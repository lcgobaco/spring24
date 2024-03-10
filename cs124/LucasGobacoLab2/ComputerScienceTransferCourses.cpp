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


    // Sort method using QuickSort algorithm
    int ComputerScienceTransferCourses::search(const std::string& key) {
        sort(true);
       return binarySearch(key, 0, this->size() - 1);
    }

    // Sort method using QuickSort algorithm
    void ComputerScienceTransferCourses::sort(bool ascending) {

        if (this->size() == 0) {
            return;
        }

        quickSort(0, this->size() - 1, ascending);
    }

    // Helper function for QuickSort algorithm
    void ComputerScienceTransferCourses::quickSort(int low, int high, bool ascending) {
        if (low < high) {
            int pi = partition(low, high, ascending);
            quickSort(low, pi - 1, ascending);
            quickSort(pi + 1, high, ascending);
        }
    }

    // Helper function to partition the array for QuickSort
    int ComputerScienceTransferCourses::partition(int low, int high, bool ascending) {
        Course pivot = this->get(high);
        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (ascending) {
                if (this->get(j).getTitle() < pivot.getTitle()) {
                    i++;
                    std::swap(this->get(i), this->get(j));
                }
            }
            else {
                if (this->get(j).getTitle() > pivot.getTitle()) {
                    i++;
                    std::swap(this->get(i), this->get(j));
                }
            }

        }

        std::swap(this->get(i + 1), this->get(high));
        return i + 1;
    }

    // Helper function for Binary Search algorithm
    int ComputerScienceTransferCourses::binarySearch(const std::string& key, int low, int high) {
        if (high >= low) {
            int mid = low + (high - low) / 2;


            std::string str1 = this->get(mid).getTitle();

            if (!str1.empty() && str1[str1.size() - 1] == '\r')
                str1.erase(str1.size() - 1);

            int comparison = key.compare(str1);

            if (comparison == 0)
                return mid;
            if (comparison < 0)
                return binarySearch(key, low, mid - 1);
            return binarySearch(key, mid + 1, high);
        }
        return -1; // Element not found
    }
