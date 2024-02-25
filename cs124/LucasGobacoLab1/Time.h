/*******************************************************

 * Program Name: Time.h

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program defines a class that stores a time.

 *******************************************************/

#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0);

    // Destructor
    ~Time();

    // Setter methods
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    // Getter methods
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
};

#endif