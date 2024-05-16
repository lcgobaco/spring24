/**
* Author: Lucas Gobaco
* Description: Manage Section using Map, HashTable, and Try-Catch
* Due Date: 05/15/2024
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "sectionHT.h"

using namespace std;

SectionHT::SectionHT(int nbuckets)
: HashTable(nbuckets) {

}
SectionHT::~SectionHT() {}

bool SectionHT::contains(string name) {
	Iterator<Section*> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get()->getSectionId() == name) {
			return true;
		}
		iter.next();
	}
	return false;
}

Section* SectionHT::get(string name) {
	Iterator<Section*> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get()->getSectionId() == name) {
			return iter.get();
		}
		iter.next();
	}
	return nullptr;
}

void SectionHT::remove(string name) {
	Iterator<Section*> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get()->getSectionId() == name) {
			this->erase(iter.get());
		}
		iter.next();
	}
}
vector<Section*> SectionHT::values() {
	vector<Section*> sections;
	Iterator<Section*> iter = this->begin();
	while (!iter.equals(this->end())) {
		sections.push_back(iter.get());
		iter.next();
	}
	return sections;
}

void SectionHT::addNew() {
	Section* section = new Section();
	cin.ignore();
	cin >> *section;
	insert(section);
}

void SectionHT::editSection() {
	string name;
	cout << "Edit section name: ";
	cin.ignore();
	getline(cin, name);
	Section* section = get(name);

	cin >> *section;
	erase(section);
	insert(section);

}
void SectionHT::deleteSection() {
	string name;
	cout << "Delete task name: ";
	cin.ignore();
	getline(cin, name);
	remove(name);
}

void SectionHT::printTable(bool complete) {

	printHeader();
	// loop thru map
	for (auto const& value : values()) {
		printRow(value);
	}

	cout << endl;
}

void SectionHT::printHeader() {
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

void SectionHT::printRow(const Section* section) {
	const char originalFill = cout.fill();
	cout << left << setw(15) << section->getSectionId()
		<< left << setw(30) << section->getTerm()
		<< left << setw(15) << section->getCourseName()
		<< endl;
	cout.fill(originalFill);
}
