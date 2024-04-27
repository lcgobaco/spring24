/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "taskHashTable.h"
#include "task.h"

using namespace std;

TaskHashTable::TaskHashTable() {}

TaskHashTable::~TaskHashTable() {}

void TaskHashTable::addNew() {
	Task task;
	cin >> task;
	insert(task.getName(), task);
}

void TaskHashTable::editTask() {
	string name;
	cout << "Edit task name: ";
	cin.ignore();
	getline(cin, name);
	Task task = get(name);
}
void TaskHashTable::deleteTask() {
	string name;
	cout << "Delete task name: ";
	cin.ignore();
	getline(cin, name);
	bool deleteMe = false;
	remove(name);
}

void TaskHashTable::printTable(bool complete) {
	// reverse the list
	for (int i = 0; i < size(); i++) {
	}

	cout << endl;
}

void TaskHashTable::printHeader() {
	const char originalFill = cout.fill();
	cout << left << setw(10) << "Term"
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
	cout << left << setw(10) << task.getTerm()
		<< left << setw(30) << task.getName()
		<< left << setw(15) << task.getStartDate().toString()
		<< left << setw(15) << task.getEndDate().toString()
		<< left << setw(10) << (task.isCompleted() ? "Done" : "Pending")
		<< endl;
	cout.fill(originalFill);
}

void TaskHashTable::printRaw(bool complete) {
	// assignment operator
	TaskHashTable tmpList = *this;

	// reverse the list
	TaskHashTable reverseList;
	tmpList.reverseStack(reverseList);

	// Show pending tasks
	while (!reverseList.isEmpty()) {
		if (reverseList.top().isCompleted() == complete) {
			cout << reverseList.top() << endl;
		}
		reverseList.pop();
	}
	cout << endl;
}
