/*
    Program to store, remove, modify, and print student records.
    Two maps are used.

    o  map<int,Student,Compare> students; // Associate an id with each student
    o  map<Student, string> grades; // Store a grade for each student

    Thus, given an integer id, the first map retrieves the student
    which is then used with the student to retrieve the student's grade.
    Printing the students is in sorted order by last name, then first name,
    then id.  This is accomplished by creating a struct that overrides
    operator () called Compare and passing it to the map for students
    given above.
*/

#include <string>
#include <iostream>
#include <ctype.h>
#include <map>
using namespace std;

class Student
{
public:
    int id;
    string first;
    string last;
    // This operator is needed for find(...) to work. Surprise!
    bool operator < (Student s) const
    {
        if (last < s.last)
        {
            return true;
        }
        if (last > s.last)
        {
            return false;
        }
        if (first < s.first)
        {
            return true;
        }
        if (first > s.first)
        {
            return false;
        }
        if (id < s.id)
        {
            return true;
        }
        if (id > s.id)
        {
            return false;
        }
        return false;
    }
};
struct Compare
{
    bool operator()(const Student& a, const Student& b) const
    {
        if (a.last < b.last)
        {
            return true;
        }
        if (a.last > b.last)
        {
            return false;
        }
        if (a.first < b.first)
        {
            return true;
        }
        if (a.first > b.first)
        {
            return false;
        }
        return a.id < b.id;
    }
};
int main ()
{
    map<Student, string, Compare> grades; // Store a grade for each student
    map<int, Student> students;  // Associate an id with each student
    bool done = false;
    while(cin.good() && !done)
    {
        cout << "A)dd R)emove M)odify P)rint Q)uit" << endl;
        Student student;
        string grade;
        char input;
        cin >> input;
        input = toupper(input);
        if (input == 'Q')
        {
            done = true;
        }
        else if (input == 'A')  // Add a student and her grade
        {

            cout << "Enter the student's information (id first_name last_name): ";
            cin >> student.id;
            cin >> student.first;
            cin >> student.last;
            cout << "Enter the student's grade: ";
            cin >> grade;
            students[student.id] = student;
            grades[student] = grade;
            cout << "Entered " << student.id << ' ' << student.first <<
                 ' ' << student.last << ' ' << grade << endl;
        }
        else if (input == 'R')  // remove a student
        {
            cout << "Enter the student's id: ";
            int id;
            cin >> id;
            map<int, Student>::iterator s = students.find(id);
            if ( s != students.end() )
            {
                cout << "There is no student with id " << id << endl;
            }
            student = s->second;
            map<Student, string>::iterator g = grades.find(student);
            grades.erase(g);
            students.erase(id);
        }
        else if (input == 'M')   // Modify the grade
        {
            cout << "Enter the student's id: ";
            int id;
            cin >> id;
            auto student =  students.find(id);  // student is an iterator
            if (student == students.end())
            {
                cout << "There is no student with id " << id << endl;
            }
            else
            {
                cout << "Enter the student's new grade: ";
                cin >> grade;
                grades[student->second] = grade;
            }
        }
        else if (input == 'P')
        {
            for (auto name : grades)
                cout << name.first.id
                     << ' ' << name.first.first
                     << ' ' << name.first.last
                     << ' ' << name.second
                     << endl;
        }
        else
        {
            done = true;
        }
    }
}


