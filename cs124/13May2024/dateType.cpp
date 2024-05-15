/*******************************************************

 * Program Name: dateType.cpp

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program implements a DateType class

 * Changes: 
    * 1. None - taken from Lab 4 template

 *******************************************************/

#include "dateType.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

string DateType::FORMAT_SEPARATOR = "-"; // default or /

// Constructor
DateType::DateType(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

// Set the date by passing in a string in month_day_year, _ to represent any FORMAT_SEPARATOR
void DateType::setDate(string dateString) {

	int pos = dateString.length() > 10 ? (int)dateString.find(" ") : 10;
	string sdate = dateString.substr(0, pos);
	pos = static_cast<int>(sdate.find('/'));
	if (pos < 0) {
		pos = static_cast<int>(sdate.find('-'));
	}
	FORMAT_SEPARATOR = string(1, sdate.at(pos));
	pos = static_cast<int>(sdate.find(FORMAT_SEPARATOR));
	month = stoi(sdate.substr(0, pos));
	sdate = sdate.substr(pos + 1); //skip past the first delimiter

	pos = (int)sdate.find(FORMAT_SEPARATOR);
	day = stoi(sdate.substr(0, pos));
	sdate = sdate.substr(pos + 1);

	year = stoi(sdate); //year is all remaining in the string

}

DateType& DateType::getDate() {
	return *this;
}

//Date format - mm/dd/yyyy
string DateType::toString() const {
	return !isEmpty() ?
		to_string(month) + FORMAT_SEPARATOR + to_string(day) + FORMAT_SEPARATOR + to_string(year) : "";
}