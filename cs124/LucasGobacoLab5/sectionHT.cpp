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
	Iterator<Section> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getSectionId() == name) {
			return true;
		}
		iter.next();
	}
	return false;
}

Section SectionHT::get(string name) {
	Iterator<Section> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getSectionId() == name) {
			return iter.get();
		}
		iter.next();
	}
	return Section();
}

void SectionHT::remove(string name) {
	Iterator<Section> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getSectionId() == name) {
			//TODO
			//this->erase(iter.get());
		}
		iter.next();
	}
}
vector<Section> SectionHT::values() {
	vector<Section> tasks;
	Iterator<Section> iter = this->begin();
	while (!iter.equals(this->end())) {
		tasks.push_back(iter.get());
		iter.next();
	}
	return tasks;
}

void SectionHT::addNew() {
	Section task;
	cin.ignore();
	cin >> task;
	string name = task.getSectionId();
	//TODO:
	//insert(task);
}

void SectionHT::editSection() {
	string name;
	cout << "Edit task name: ";
	cin.ignore();
	getline(cin, name);
	Section task = get(name);

	cin >> task;
	//TODO:
	//erase(task);
	//insert(task);

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

void SectionHT::printRow(const Section task) {
	const char originalFill = cout.fill();
	cout << left << setw(15) << task.getSectionId()
		<< left << setw(30) << task.getTerm()
		<< left << setw(15) << task.getCourseName()
		<< endl;
	cout.fill(originalFill);
}

void SectionHT::printRaw(bool complete) {
	cout << endl;
}
