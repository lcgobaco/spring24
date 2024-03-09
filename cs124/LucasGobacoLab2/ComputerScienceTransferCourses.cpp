#include "ArrayList.h" // Assuming ArrayList.h contains the definition of ArrayList
#include "Course.h"    // Assuming Course.h contains the definition of the Course class

template <typename T>
class ComputerScienceTransferCourses : public ArrayList<Course> {
public:
    // Constructor
    ComputerScienceTransferCourses() {}

    // Destructor
    ~ComputerScienceTransferCourses() {}

    // Sort method using QuickSort algorithm
    void sort() {
        quickSort(0, this->size() - 1);
    }

    // Search method using Binary Search algorithm
    int search(const Course& key) {
        return binarySearch(key, 0, this->size() - 1);
    }

private:
    // Helper function for QuickSort algorithm
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    // Helper function to partition the array for QuickSort
    int partition(int low, int high) {
        Course pivot = this->get(high);
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (this->get(j) < pivot) {
                i++;
                std::swap(this->get(i), this->get(j));
            }
        }

        std::swap(this->get(i + 1), this->get(high));
        return i + 1;
    }

    // Helper function for Binary Search algorithm
    int binarySearch(const Course& key, int low, int high) {
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
};
