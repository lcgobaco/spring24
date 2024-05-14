/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program tests the TaskMenu class

 * Changes: 
    * 1. Changed fill characters from '*' to '-'
	* 2. Added 1 to all setw values in showBanner method

 *******************************************************/

#include <iostream>
#include <iomanip>
#include "taskMenu.h"

using namespace std;

void showBanner();

int main() {
	showBanner();
	TaskMenu menu;
	menu.activate();

	return 0;
}

/**
 * showBanner - print me first
 **/
void showBanner() {
	const char originalFill = cout.fill();
	cout << setfill('-') << setw(51) << "-" << endl << endl;
	cout << "\tApplication to Manage Tasks" << endl;
	cout << "\t---------------------------" << endl;
	cout << "\tProgram written by: Lucas Gobaco"<< endl;
	cout << "\tCourse info: CS-124-03" << endl;
	cout << "\tDue date: 5/13/2024"<< endl << endl;
	cout << setfill('-') << setw(51) << "-" << endl << endl;
	cout.fill(originalFill);
}