/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 8 April 2024

 * Description: This program tests the hash table class.

 *******************************************************/

#include <string>
#include <iostream>
#include <unordered_map>
#include "hashtable.h"

using namespace std;

class Person {
public:
    int id;
    string name;
    string grade;

    bool operator==(const Person& other) const {
        return name == other.name && grade == other.grade;
    }

    int length() const {
        return name.length();
    }

    int at(int index) const {
        return name.at(index);
    }
};

int main()
{
    HashTable<Person> students;

    // Insert 3 rows of data and hashtable each name to letter grade
    students.insert(Person{101, "Carl", "B+"});
    students.insert(Person{102, "Joe", "C"});
    students.insert(Person{103, "Sarah", "A"});

    // Print out the data
    int i = 0;
    for (Iterator<Person> iter = students.begin(); !iter.equals(students.end()); iter.next()) {
        cout << iter.get().id << " " << iter.get().name << " " << iter.get().grade << endl;
        i++;
    }

    cout << "Number of iterations: " << i << endl;

    return 0;
}
