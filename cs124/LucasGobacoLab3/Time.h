/*******************************************************

 * Program Name: Time.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a class that stores a time.

 *******************************************************/

#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
public:
    int hour;
    int minute;
    int second;

public:
    /**
     * Constructs a time with hours, minutes, and seconds as parameters.
     * @param h the hours
     * @param m the minutes
     * @param s the seconds
    */
    Time(int h = 0, int m = 0, int s = 0);

    /**
     * Destructs a time object.
    */
    ~Time();

    /**
     * Sets the hour of the time.
     * @param h the hour
    */
    void setHour(int h);

    /**
     * Sets the minute of the time.
     * @param m the minute
    */
    void setMinute(int m);

    /**
     * Sets the second of the time.
     * @param s the second
    */
    void setSecond(int s);

    /**
     * Gets the hour of the time.
     * @return the hour
    */
    int getHour() const;

    /**
     * Gets the minute of the time.
     * @return the minute
    */
    int getMinute() const;

    /**
     * Gets the second of the time.
     * @return the second
    */
    int getSecond() const;
};

#endif