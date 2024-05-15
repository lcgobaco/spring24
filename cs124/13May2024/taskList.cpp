/*******************************************************

 * Program Name: taskList.cpp

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program implements a TaskList class

 * Changes: 
    * 1. In addNew method, changed the push_back(task) to push(task) in order to use the push method from the LinkedSet class
    * 2. In the editTask, deleteTask, printTable, and printRaw method used the iterator to travesre the set to achieve the same functionality
	* 3. Added 1 to all setw values in printHeader and printRow methods
	* 4. Changed fill characters from '*' to '-'

 *******************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "taskList.h"
#include "task.h"

using namespace std;

TaskList::TaskList() {}

TaskList::~TaskList() {}

void TaskList::addNew() {	
	Task task;
	cin >> task;
	push_back(task);
}

void TaskList::editTask() {
    // no need to create new instance of TaskList
	string name;
	cout << "Edit task name: ";
	cin.ignore();
	getline(cin, name);

    // use iterator to traverse the list
    Iterator<Task> iter = this->begin();
    while (!iter.equals(this->end())) {
        if (iter.get().getName() == name) {
            cout << "Enter new name: ";
            cin >> name;
            iter.get().setName(name);
			break;
        }
		iter.next();
    }
}
void TaskList::deleteTask() {
	// no need to create new in this case
	string name;
	cout << "Delete task name: ";
	cin.ignore();
	getline(cin, name);

    // use iterator to traverse the list
    Iterator<Task> iter = this->begin();
    while (!iter.equals(this->end())) {
        if (iter.get().getName() == name) {
            erase(iter);
        }
		iter.next();
    }
}

void TaskList::printTable(bool complete) {
	// Show pending tasks
	printHeader();
	// use iterator to traverse the list
    Iterator<Task> iter = this->begin();
    while (!iter.equals(this->end())) {
		if (iter.get().isCompleted() == complete)
        	printRow(iter.get());
		iter.next();
    }
}

void TaskList::printHeader() {
	const char originalFill = cout.fill();
	cout << left << setw(16) << "Term"
		<< left << setw(31) << "Name"
		<< left << setw(16) << "Start Date"
		<< left << setw(16) << "End Date"
		<< left << setw(11) << "Status"
		<< endl;
	cout << setfill('-') << setw(81) << "-" << endl;
	cout.fill(originalFill);
}

void TaskList::printRow(const Task task) {
	const char originalFill = cout.fill();
	cout << left << setw(16) << task.getTerm()
		<< left << setw(31) << task.getName()
		<< left << setw(16) << task.getStartDate().toString()
		<< left << setw(16) << task.getEndDate().toString()
		<< left << setw(11) << (task.isCompleted() ? "Done" : "Pending")
		<< endl;
	cout.fill(originalFill);
}

void TaskList::printRaw(bool complete) {
	// use iterator to traverse the list
    Iterator<Task> iter = this->begin();
    while (!iter.equals(this->end())) {
        cout << iter.get() << endl;
		iter.next();
    }
}