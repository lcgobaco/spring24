#pragma once
#include <string>

using namespace std;

class Person
{
public:
	Person(string first = "", string last = "");
	void setFirst(string first);
	void setLast(string last);
	string getName();
	void printPerson();		// print person's first and last name

private:
	string firstName; //variable to store the first name
	string lastName;  //variable to store the last name
};
