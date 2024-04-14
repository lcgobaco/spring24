/*******************************************************

 * Program Name: datetype.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a class that stores a date.

 *******************************************************/

#include "datetype.h"

// Overloaded input/output operators
istream& operator>>(istream& in, DateType& date) {
    // Read date details from input stream
    in >> date.month >> date.day >> date.year;
    return in;
}

ostream& operator<<(ostream& out, const DateType& date) {
    // Write date details to output stream
    out << date.month << "/" << date.day << "/" << date.year;
    return out;
}