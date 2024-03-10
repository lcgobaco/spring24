#ifndef COMPUTER_SCIENCE_TRANSFER_COURSES_H
#define COMPUTER_SCIENCE_TRANSFER_COURSES_H

#include "ArrayList.h"
#include "Course.h"

template <class T>
class ComputerScienceTransferCourses : public ArrayList<Course> {
public:
    ComputerScienceTransferCourses();
    ~ComputerScienceTransferCourses();

    void sort();

private:
    void quickSort(int low, int high);
    int partition(int low, int high);
    int binarySearch(const Course& key, int low, int high);
};

#include "ComputerScienceTransferCourses.cpp"

#endif // COMPUTER_SCIENCE_TRANSFER_COURSES_H
