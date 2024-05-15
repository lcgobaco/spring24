/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "taskMenu.h"
#include "dateTime.h"
#include "taskException.h"

using namespace std;

TaskMenu::TaskMenu() : Menu("Main Menu") {
	addOption("a", "Add task");
	addOption("e", "Edit task");
	addOption("d", "Delete task");
	addOption("p", "List pending tasks");
	addOption("c", "List completed tasks");
	addOption("x", "Exit");

	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list = new TaskList();
	table = new TaskHashTable(100);
	try {
		init();}
	catch (const TaskException& e) {
		cout << e.what() << endl;
		exit(1);
	}
}
TaskMenu::~TaskMenu() {
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//delete list;
	delete table;
	inFile.close();
}

void TaskMenu::init(){
	inFile.open(TASK_DATA);

	if (inFile.fail()) {
		throw runtime_error("Could not open file " + TASK_DATA);
	}

	string text;
	string line = "";
	bool firstRow = true;
	while (getline(inFile, line)) {
		// Skip the first row
		if (firstRow) {
			firstRow = false;
			continue;
		}
		stringstream ss(line);
		Task task;
		getline(ss, text, ',');
		task.setTerm(text);
		getline(ss, text, ',');
		task.setName(text);
		getline(ss, text, ',');
		task.setStartDate(text);
		getline(ss, text, ',');
		task.setEndDate(text);
		getline(ss, text, ',');
		task.setStatus(stoi(text));	// value =1 means DONE! and value = 0 is pending
		//list->push(task);
		table->insert(task);
	}
	inFile.close();
}

void TaskMenu::viewPendingTasks() {
	showOption(getName("p"));
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list->printTable(false);
	table->printTable(false);
}

void TaskMenu::viewCompletedTasks() {
	showOption(getName("c"));
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list->printTable(true);
	table->printTable(true);
}

void TaskMenu::addNewTask() {
	showOption(getName("a"));
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list->addNew();
	try {
		table->addNew();
		cout << endl;
	} catch (const TaskException& e) {
		cout << e.what() << endl;
		cout << endl;
		return;
	}
	cout << endl;
}

void TaskMenu::editTask() {
	showOption(getName("e"));
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list->editTask();
	try {
		table->editTask();
		cout << endl;
	} catch (const TaskException& e) {
		cout << e.what() << endl;
		cout << endl;
		return;
	}
}

void TaskMenu::deleteTask() {
	showOption(getName("d"));
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list->deleteTask();
	try {
		table->deleteTask();
		cout << endl;
	} catch (const TaskException& e) {
		cout << e.what() << endl;
		cout << endl;
		return;
	}
}

void TaskMenu::activate() {
	char command = COMMAND::ADD;
	while (command != EXIT) {
		command = doMenuOption();
		switch (command) {
		case ADD:
			addNewTask();
			break;
		case EDIT:
			editTask();
			break;
		case DELETE:
			deleteTask();
			break;
		case PENDING:
			viewPendingTasks();
			break;
		case DONE:
			viewCompletedTasks();
			break;
		case EXIT:
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Not a valid command. Please try again." << endl << endl;
			break;
		}
	}
}

void TaskMenu::showOption(const string title) {
	cout << "***** " << title << " *****" << endl;
}
