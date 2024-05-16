/**
* Author: John Doe
* Description: Manage GradeScales using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "gradeScale.h"
#include "gradeScaleHT.h"

using namespace std;

GradeScaleHT::GradeScaleHT(int nbuckets)
: HashTable(nbuckets) {

}
GradeScaleHT::~GradeScaleHT() {}

bool GradeScaleHT::contains(string name) {
	Iterator<GradeScale> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getGradeScaleId() == name) {
			return true;
		}
		iter.next();
	}
	return false;
}

GradeScale GradeScaleHT::get(string name) {
	Iterator<GradeScale> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getGradeScaleId() == name) {
			return iter.get();
		}
		iter.next();
	}
	return GradeScale();
}

void GradeScaleHT::remove(string name) {
	Iterator<GradeScale> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getGradeScaleId() == name) {
			this->erase(iter.get());
		}
		iter.next();
	}
}
vector<GradeScale> GradeScaleHT::values() {
	vector<GradeScale> GradeScales;
	Iterator<GradeScale> iter = this->begin();
	while (!iter.equals(this->end())) {
		GradeScales.push_back(iter.get());
		iter.next();
	}
	return GradeScales;
}

void GradeScaleHT::addNew() {
	GradeScale GradeScale;
	cin.ignore();
	cin >> GradeScale;
	string name = GradeScale.getGradeScaleId();
	insert(GradeScale);
}

void GradeScaleHT::editGradeScale() {
	string name;
	cout << "Edit GradeScale name: ";
	cin.ignore();
	getline(cin, name);
	GradeScale GradeScale = get(name);

		cin >> GradeScale;
		erase(GradeScale);
		insert(GradeScale);

}
void GradeScaleHT::deleteGradeScale() {
	string name;
	cout << "Delete GradeScale name: ";
	cin.ignore();
	getline(cin, name);
	remove(name);
}

void GradeScaleHT::printTable(bool complete) {

	printHeader();
	// loop thru map
	for (auto const& value : values()) {
			printRow(value);
	}

	cout << endl;
}

void GradeScaleHT::printHeader() {
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

void GradeScaleHT::printRow(const GradeScale GradeScale) {
	const char originalFill = cout.fill();
	// TODO:
	// cout << left << setw(15) << GradeScale.getTerm()
	// 	<< left << setw(30) << GradeScale.getName()
	// 	<< left << setw(15) << GradeScale.getStartDate().toString()
	// 	<< left << setw(15) << GradeScale.getEndDate().toString()
	// 	<< left << setw(10) << (GradeScale.isCompleted() ? "Done" : "Pending")
	// 	<< endl;
	cout.fill(originalFill);
}

void GradeScaleHT::printRaw(bool complete) {

	cout << endl;
}
