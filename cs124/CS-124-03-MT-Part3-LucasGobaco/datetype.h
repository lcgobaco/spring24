/*******************************************************

 * Program Name: datetype.h

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program defines a class that stores a date.

 *******************************************************/

#ifndef H_DATETYPE
#define H_DATETYPE

#include <iostream>
#include <string>

using namespace std;

class DateType {
private:
    int month;
    int day;
    int year;

public:
    // Constructors
    DateType() : month(1), day(1), year(1900) {}
    DateType(int month, int day, int year) : month(month), day(day), year(year) {}

    // Accessors
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Mutators
    void setMonth(int month) { this->month = month; }
    void setDay(int day) { this->day = day; }
    void setYear(int year) { this->year = year; }

    // Overloaded input/output operators
    friend istream& operator>>(istream& in, DateType& date);
    friend ostream& operator<<(ostream& out, const DateType& date);
};

#endif