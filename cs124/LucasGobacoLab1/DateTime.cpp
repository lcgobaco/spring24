/*******************************************************

 * Program Name: DateTime.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program implements a class that stores a date and time.

 *******************************************************/

#include "DateTime.h"
#include "Utils.h"

using namespace std;

// Constructor
DateTime::DateTime(int h, int m, int s, int mon, int d, int y)
    : Time(h, m, s), month(mon), day(d), year(y) {}

DateTime::DateTime(string datetime) {
    vector<string> tokens = splitString(datetime, '-');
    setYear(stoi(tokens[0]));
    setMonth(stoi(tokens[1]));
    setDay(stoi(tokens[2]));
}

// Destructor
DateTime::~DateTime() {
    std::cout << "DateTime object is being destroyed" << std::endl;
}

// Setter methods
void DateTime::setMonth(int mon) {
    month = mon;
}

void DateTime::setDay(int d) {
    day = d;
}

void DateTime::setYear(int y) {
    year = y;
}

// Getter methods
int DateTime::getMonth() const {
    return month;
}

int DateTime::getDay() const {
    return day;
}

int DateTime::getYear() const {
    return year;
}
