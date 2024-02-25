/*******************************************************

 * Program Name: DateTime.h

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program defines a class that stores a date and time.

 *******************************************************/

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <iostream>
#include "Time.h"

class DateTime : public Time {
private:
    int month;
    int day;
    int year;

public:
    // Constructor
    DateTime(int h = 0, int m = 0, int s = 0, int mon = 0, int d = 0, int y = 0);

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
};

#endif // DATE_TIME_H
