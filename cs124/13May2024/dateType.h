/*******************************************************

 * Program Name: dateType.h

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program defines a DateType class
 
 * Changes: 
    * 1. None - taken from Lab 4 template

 *******************************************************/

#pragma once

#include <string>
using namespace std;

class DateType {
public:
	DateType(int m = 0, int d = 0, int y = 0);
	~DateType() {};

	//Mutator functions
	void setMonth(int m) { month = m; };
	void setDay(int d) { day = d; };
	void setYear(int y) { year = y; };

	//string format mm/dd/yyyy
	void setDate(string);

	//Accessor functions
	int getMonth() const { return month; };
	int getDay() const { return day; };
	int getYear() const { return year; };
	DateType& getDate();

	string toString() const; // mm/dd/yyyy
	bool isEmpty() const {
		return month == 0 && day == 0 && year == 0;
	};

	static string FORMAT_SEPARATOR;

protected:
	int month;
	int day;
	int year;
};