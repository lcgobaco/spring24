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
    *this = DateTime(stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]), stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
}

DateTime::DateTime(std::chrono::system_clock::time_point datetime) {

    std::time_t currentTime = std::chrono::system_clock::to_time_t(datetime);

    // Convert the time_t object to a tm struct
    std::tm* timeInfo = std::localtime(&currentTime);

    // Extract individual components of the current datetime
    int year = timeInfo->tm_year + 1900;   // tm_year is years since 1900
    int month = timeInfo->tm_mon + 1;       // tm_mon is months since January (0-based)
    int day = timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;
    int second = timeInfo->tm_sec;
    // DateTime(int h, int m, int s, int mon, int d, int y)
    *this = DateTime(hour, minute, second, month, day, year);
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

// Other methods
std::string DateTime::toString() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}
