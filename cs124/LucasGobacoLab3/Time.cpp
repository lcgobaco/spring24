/*******************************************************

 * Program Name: Time.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a class that stores a time.

 *******************************************************/

#include "Time.h"

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

Time::~Time() {}

void Time::setHour(int h) {
    hour = h;
}

void Time::setMinute(int m) {
    minute = m;
}

void Time::setSecond(int s) {
    second = s;
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}