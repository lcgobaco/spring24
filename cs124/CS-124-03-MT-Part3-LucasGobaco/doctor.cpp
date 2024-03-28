/*******************************************************

 * Program Name: doctor.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a class that stores a doctor's first and last name and specialty.

 *******************************************************/

#include <iostream>
#include "doctor.h"

//constructor
Doctor::Doctor(string first, string last, string specialty) : Person(first, last) {
    this->specialty = specialty;
}

//getter for specialty
string Doctor::getSpecialty() const {
    return specialty;
}

//setter for specialty
void Doctor::setSpecialty(string specialty) {
    this->specialty = specialty;
}

//input operator
istream& operator>>(istream& in, Doctor& doctor) {
    string first, last, specialty;
    in >> first >> last >> specialty;
    doctor.setFirstName(first);
    doctor.setLastName(last);
    doctor.setSpecialty(specialty);
    return in;
}

//output operator
ostream& operator<<(ostream& out, const Doctor& doctor) {
    out << doctor.getFirstName() << " " << doctor.getLastName() << " (" << doctor.getSpecialty() << ")";
    return out;
}