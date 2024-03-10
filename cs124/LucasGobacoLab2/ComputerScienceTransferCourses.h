#ifndef COMPUTER_SCIENCE_TRANSFER_COURSES_H
#define COMPUTER_SCIENCE_TRANSFER_COURSES_H

#include "ArrayList.h"
#include "Course.h"

class ComputerScienceTransferCourses : public ArrayList<Course> {
public:
    ComputerScienceTransferCourses() {};
    ~ComputerScienceTransferCourses() {};

    void sort();
    int search(const std::string& key);

private:
    void quickSort(int low, int high);
    int partition(int low, int high);
    int binarySearch(const std::string& key, int low, int high);
};


#endif // COMPUTER_SCIENCE_TRANSFER_COURSES_H
