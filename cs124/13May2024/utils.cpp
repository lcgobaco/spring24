/*******************************************************

 * Program Name: utils.cpp

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program implements utility functions

 * Changes: 
    * 1. None - taken from Lab 4 template

 *******************************************************/

#define _CRT_SECURE_NO_WARNINGS // supress localtime warning

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "utils.h"

using namespace std;

//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec) {
	time_t t = std::time(0);    // get time now
	tm* now = localtime(&t);

	mo = now->tm_mon + 1;
	d = now->tm_mday;
	yr = now->tm_year + 1900;

	hr = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
}

string getDateTimeNow() {
	int mo, d, yr, hr, min, sec;
	// Format ex. 2/6/2023 18:30:01   
	getCurrentTime(mo, d, yr, hr, min, sec);
	/*DateTime dt;
	dt.setMonth(mo);
	dt.setDay(d);
	dt.setYear(yr);
	dt.setHour(hr);
	dt.setMinute(min);
	dt.setSecond(sec);

	return dt.toString();
	*/
	return "";
}

void openFile(fstream& inFile, string fileName) {
	inFile.open(fileName);
}