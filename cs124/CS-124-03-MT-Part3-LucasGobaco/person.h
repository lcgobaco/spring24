/*******************************************************

 * Program Name: person.h

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program defines a class that stores a person's first and last name.

 *******************************************************/

#ifndef H_PERSON
#define H_PERSON

#include <string>

using namespace std;

class Person {
public:

    //constructor
    Person(string first = "", string last = "");

    //getter for first name
    string getFirstName() const;

    //setter for first name
    void setFirstName(string first);

    //getter for last name
    string getLastName() const;

    //setter for last name
    void setLastName(string last);

 private:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
};

#endif