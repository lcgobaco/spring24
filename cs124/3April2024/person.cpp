/*******************************************************

 * Program Name: person.cpp

 * Author: Lucas Gobaco

 * Date: 3 April 2024

 * Description: This program allows the user to add, remove, modify, or print student names and grades.

 *******************************************************/

#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
public:
    int id;
    string name;
    string grade;
};

bool compareByName(const pair<int, Person>& a, const pair<int, Person>& b) {
    return a.second.name < b.second.name;
}

int main ()
{
    map<int, Person> students;

    bool done = false;
    while(cin && !done)
    {
        cout << "A)dd R)emove M)odify P)rint Q)uit" << endl;
        
        char input;
        cin >> input;
        input = toupper(input);
        if (input == 'Q')
        {
            done = true;
        }
        else if (input == 'A')
        {
            // add a new student and map id to student
            Person student;
            cout << "Enter student ID: ";
            cin >> student.id;
            cout << "Enter student name: ";
            cin >> student.name;
            cout << "Enter student grade: ";
            cin >> student.grade;
            students[student.id] = student;
        }
        else if (input == 'R')
        {
            // find id from map and remove
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            students.erase(id);
        }
        else if (input == 'M')
        {
            // find student and modify name and grade
            int id;
            cout << "Enter student ID to modify: ";
            cin >> id;
            if (students.find(id) != students.end()) {
                    cout << "Enter new student name: ";
                    cin >> students[id].name;
                    cout << "Enter new student grade: ";
                    cin >> students[id].grade;
            } else {
                    cout << "Student not found." << endl;
            }
        }
        else if (input == 'P')
        {
            // print all students
            vector<pair<int, Person>> sortedStudents(students.begin(), students.end());
            sort(sortedStudents.begin(), sortedStudents.end(), compareByName);
            for (const auto& pair : sortedStudents) {
                    cout << pair.second.name << " (" << pair.first << "): " << pair.second.grade << endl;
            }
        }
        else
        {
            done = true;
        }
    }
    
    return 0;
}