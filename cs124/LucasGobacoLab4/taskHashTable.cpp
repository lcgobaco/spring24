/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "taskHashTable.h"
#include "taskException.h"

using namespace std;

TaskHashTable::TaskHashTable(int nbuckets)
: HashTable(nbuckets) {

}
TaskHashTable::~TaskHashTable() {}

bool TaskHashTable::contains(string name) {
	Iterator<Task> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getName() == name) {
			return true;
		}
		iter.next();
	}
	return false;
}

Task TaskHashTable::get(string name) {
	Iterator<Task> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getName() == name) {
			return iter.get();
		}
		iter.next();
	}
	return Task();
}

void TaskHashTable::remove(string name) {
	Iterator<Task> iter = this->begin();
	while (!iter.equals(this->end())) {
		if (iter.get().getName() == name) {
			this->erase(iter.get());
		}
		iter.next();
	}
}
vector<Task> TaskHashTable::values() {
	vector<Task> tasks;
	Iterator<Task> iter = this->begin();
	while (!iter.equals(this->end())) {
		tasks.push_back(iter.get());
		iter.next();
	}
	return tasks;
}

void TaskHashTable::addNew() {
	Task task;
	cin >> task;
	string name = task.getName();
	if (contains(name)) {
		throw TaskException(name, "Cannot add. Task already exists");
	} else {
		insert(task);
	}
}

void TaskHashTable::editTask() {
	string name;
	cout << "Edit task name: ";
	cin.ignore();
	getline(cin, name);
	Task task = get(name);

	if (contains(name)) {
		cin >> task;
		erase(task);
		insert(task);
	} else {
		throw TaskException(name, "Cannot edit. Task not found");
	}

}
void TaskHashTable::deleteTask() {
	string name;
	cout << "Delete task name: ";
	cin.ignore();
	getline(cin, name);
	if (contains(name)) {
		remove(name);
	} else {
		throw TaskException(name,"Cannot delete. Task not found");
	}
}

void TaskHashTable::printTable(bool complete) {

	printHeader();
	// loop thru map
	for (auto const& value : values()) {
		if (value.isCompleted() == complete) {
			printRow(value);
		}
	}

	cout << endl;
}

void TaskHashTable::printHeader() {
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

void TaskHashTable::printRow(const Task task) {
	const char originalFill = cout.fill();
	cout << left << setw(15) << task.getTerm()
		<< left << setw(30) << task.getName()
		<< left << setw(15) << task.getStartDate().toString()
		<< left << setw(15) << task.getEndDate().toString()
		<< left << setw(10) << (task.isCompleted() ? "Done" : "Pending")
		<< endl;
	cout.fill(originalFill);
}

void TaskHashTable::printRaw(bool complete) {

	cout << endl;
}
