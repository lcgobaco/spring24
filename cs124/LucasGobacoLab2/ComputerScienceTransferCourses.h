/*******************************************************

 * Program Name: ComputerScienceTransferCourses.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program defines a class that manages a list of computer science transfer courses.

 *******************************************************/

#ifndef COMPUTER_SCIENCE_TRANSFER_COURSES_H
#define COMPUTER_SCIENCE_TRANSFER_COURSES_H

#include "ArrayList.h"
#include "Course.h"

class ComputerScienceTransferCourses : public ArrayList<Course> {
public:
    ComputerScienceTransferCourses() {};
    ~ComputerScienceTransferCourses() {};

    void sort(bool ascending = true);
    int search(const std::string& key);

private:
    void quickSort(int low, int high, bool ascending);
    int partition(int low, int high, bool ascending);
    int binarySearch(const std::string& key, int low, int high);
};


#endif // COMPUTER_SCIENCE_TRANSFER_COURSES_H
