/**
* Author: John Doe
* Description: Manage Facultys using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "facultyHT.h"

using namespace std;

FacultyHT::FacultyHT(int nbuckets)
: HashTable(nbuckets) {

}
FacultyHT::~FacultyHT() {}

bool FacultyHT::contains(string name) {
	Iterator<Faculty> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getFacultyId() == name) {
			return true;
		}
		iter.next();
	}
	return false;
}

Faculty FacultyHT::get(string name) {
	Iterator<Faculty> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getFacultyId() == name) {
			return iter.get();
		}
		iter.next();
	}
	return Faculty();
}

void FacultyHT::remove(string name) {
	Iterator<Faculty> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getFacultyId() == name) {
			this->erase(iter.get());
		}
		iter.next();
	}
}
vector<Faculty> FacultyHT::values() {
	vector<Faculty> Facultys;
	Iterator<Faculty> iter = this->begin();
	while (!iter.equals(this->end())) {
		Facultys.push_back(iter.get());
		iter.next();
	}
	return Facultys;
}

void FacultyHT::addNew() {
	Faculty faculty;
	cin.ignore();
	cin >> faculty;
	string name = faculty.getFacultyId();
	insert(faculty);
}

void FacultyHT::editFaculty() {
	string name;
	cout << "Edit Faculty name: ";
	cin.ignore();
	getline(cin, name);
	Faculty faculty = get(name);

	cin >> faculty;
	erase(faculty);
	insert(faculty);

}
void FacultyHT::deleteFaculty() {
	string name;
	cout << "Delete Faculty name: ";
	cin.ignore();
	getline(cin, name);
	remove(name);
}

void FacultyHT::printTable(bool complete) {

	printHeader();
	// loop thru map
	for (auto const& value : values()) {
		printRow(value);
	}

	cout << endl;
}

void FacultyHT::printHeader() {
	const char originalFill = cout.fill();
	cout << left << setw(15) << "Term"
		<< left << setw(30) << "Name"
		<< left << setw(15) << "Start Date"
		<< left << setw(15) << "End Date"
		<< left << setw(10) << "Status"
		<< endl;
	cout << setfill('=') << setw(80) << "=" << endl;
	cout.fill(originalFill);
}

void FacultyHT::printRow(const Faculty Faculty) {
	const char originalFill = cout.fill();
	cout << left << setw(15) << Faculty.getFacultyId()
		<< left << setw(30) << Faculty.getFirstName()
		<< left << setw(15) << Faculty.getLastName()
		<< left << setw(15) << Faculty.getDepartment()
		<< endl;
	cout.fill(originalFill);
}

void FacultyHT::printRaw(bool complete) {

	cout << endl;
}
