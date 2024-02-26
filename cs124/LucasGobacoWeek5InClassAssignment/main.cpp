/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 23 February 2024

 * Description: This program creates and manages an unordered array list of course objects.

 *******************************************************/

#include <iostream> 
#include <vector>
#include "UnorderedArrayList.h"
#include "Course.h"

using namespace std;

int main() {
    UnorderedArrayList<Course> list(100);

    vector<Course> courses, coursesNotFound;

    courses.push_back(Course("CSC", 125, "Computer Science I", "Introduction to computer science", "", 3));
    courses.push_back(Course("CSC", 135, "Computer Science II", "Introduction to computer science", "CSC 125", 3));
    courses.push_back(Course("CSC", 145, "Computer Science III", "Introduction to computer science", "CSC 135", 3));
    courses.push_back(Course("CSC", 155, "Computer Science IV", "Introduction to computer science", "CSC 145", 3));
    courses.push_back(Course("CSC", 165, "Computer Science V", "Introduction to computer science", "CSC 155", 3));
    // TODO

    coursesNotFound.push_back(Course("CSC", 175, "Computer Science VI", "Introduction to computer science", "CSC 165", 3));
    coursesNotFound.push_back(Course("CSC", 185, "Computer Science VII", "Introduction to computer science", "CSC 175", 3));

    for (int i = 0; i < courses.size(); i++) {
        list.insert(courses[i]);
    }

    cout << "Is List Size Correct? " << (list.size() == courses.size()) << endl;

    for (int i = 0; i < courses.size(); i++) {
        cout << "Is Course " << i << " Correct? " << (list.search(courses[i]) == i) << endl;
    }

    cout << "Removing Course 0...";

    list.remove(courses[0]);

    cout << "Is List Size Correct? " << (list.size() == courses.size()-1) << endl;
    cout << "Is Removed Item Missing? " << (list.search(courses[0]) == -1) << endl;

    for (int i = 0; i < coursesNotFound.size(); i++) {
        cout << "Is Course " << i << " Correct? " << (list.search(coursesNotFound[i]) == -1) << endl;
    }

    cout << "Is Course " << 1 << " Correct? " << (list.search(courses[2]) == 1) << endl;
    cout << "Replacing Course 1..." << endl;
    list.replaceAt(1, coursesNotFound[0]);
    cout << "Is Course " << 1 << " Replaced? " << (list.search(courses[2]) == -1) << endl;
    cout << "Is Course " << 1 << " Correct? " << (list.search(coursesNotFound[0]) == 1) << endl;

    return 0;
}