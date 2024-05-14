/*******************************************************

 * Program Name: utils.h

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program defines utility functions

 * Changes: 
    * 1. None - taken from Lab 4 template

 *******************************************************/

#pragma once
#include <fstream>
#include <string>

using namespace std;

void openFile(fstream& inFile, string fileName);

//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec);

string getDateTimeNow();