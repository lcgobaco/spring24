/*******************************************************

 * Program Name: DateTime.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program implements a class that stores a date and time.

 *******************************************************/

#include "DateTime.h"
#include "Utils.h"
#include <vector>
#include <string>

using namespace std;

// Constructor
DateTime::DateTime(int h, int m, int s, int mon, int d, int y)
    : Time(h, m, s), month(mon), day(d), year(y) {}

DateTime::DateTime(string datetime) {
    // 2/10/2024 20:30:14
    std::replace(datetime.begin(), datetime.end(), ' ', '/');
    std::replace(datetime.begin(), datetime.end(), ':', '/');
    vector<string> tokens = splitString(datetime, '/');
    *this = DateTime(stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]), stoi(tokens[3]), stoi(tokens[1]), stoi(tokens[2]));
}

// Destructor
DateTime::~DateTime() {
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
