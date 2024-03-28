/*******************************************************

 * Program Name: person.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a class that stores a person's first and last name.

 *******************************************************/

#include "person.h"

//constructor
Person::Person(string first, string last) {
    firstName = first;
    lastName = last;
}

//getter for first name
string Person::getFirstName() const {
    return firstName;
}

//setter for first name
void Person::setFirstName(string first) {
    firstName = first;
}

//getter for last name
string Person::getLastName() const {
    return lastName;
}

//setter for last name
void Person::setLastName(string last) {
    lastName = last;
}