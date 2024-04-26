/*******************************************************

 * Program Name: DateTime.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a class that stores a date and time.

 *******************************************************/

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <iostream>
#include <ctime>
#include "Time.h"

using namespace std;

class DateTime : public Time {
private:
    int month;
    int day;
    int year;

public:
    /**
     * Constructs a date and time with no hour, minute, second, month, day, or year.
     */
    DateTime(int h = 0, int m = 0, int s = 0, int mon = 0, int d = 0, int y = 0);

    /**
     * Constructs a date and time with a given hour, minute, second, month, day, and year.
     * @param datetime the date and time in the format "YYYY-MM-DD HH:MM:SS"
     */
    DateTime(string datetime);

    DateTime(std::chrono::system_clock::time_point datetime);

    // Destructor
    ~DateTime();

    // Setter methods
    void setMonth(int mon);
    void setDay(int d);
    void setYear(int y);

    // Getter methods
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Other methods
    string toString() const;
};

#endif // DATE_TIME_H
