/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "assignmentMenu.h"

using namespace std;

/*
doList - display all data from the root of the tree.
doView - view individual assignment and view group of assignments in rows and columns
doAdd - add to tree.
doEdit - edit any fields
doRemove - remove a node from the tree
calculateGrade - Implement your grade and display.
doSave - save data to .csv file
*/
AssignmentMenu::AssignmentMenu() : Menu("Main Menu") {
	addOption("l", "List Assignments");
	addOption("v", "View Assignment");
	addOption("a", "Add Assignment");
	addOption("e", "Edit Assignment");
	addOption("r", "Remove Assignment");
	addOption("c", "Calculate Grade");
	addOption("s", "Save");
	addOption("x", "Edit");

	//TODO and DONE: Replaced TaskList with TaskHashTable
	//list = new TaskList();
	init();
}

AssignmentMenu::~AssignmentMenu() {
	//TODO and DONE: Replaced TaskList with TaskHashTable
	//delete list;
	//delete table;
	inFile.close();
}

void AssignmentMenu::init(){
	// inFile.open(TASK_DATA);

	// if (inFile.fail()) {
	// 	throw runtime_error("Could not open file " + TASK_DATA);
	// }

	// string text;
	// string line = "";
	// bool firstRow = true;
	// while (getline(inFile, line)) {
	// 	// Skip the first row
	// 	if (firstRow) {
	// 		firstRow = false;
	// 		continue;
	// 	}
	// 	stringstream ss(line);
	// 	Task task;
	// 	getline(ss, text, ',');
	// 	task.setTerm(text);
	// 	getline(ss, text, ',');
	// 	task.setName(text);
	// 	getline(ss, text, ',');
	// 	task.setStartDate(text);
	// 	getline(ss, text, ',');
	// 	task.setEndDate(text);
	// 	getline(ss, text, ',');
	// 	task.setStatus(stoi(text));	// value =1 means DONE! and value = 0 is pending
	// 	//list->push(task);
	// 	table->insert(task);
	// }
	// inFile.close();
}

void AssignmentMenu::doList() {
	showOption(getName("l"));
	//TODO:
}

void AssignmentMenu::doView() {
	showOption(getName("V"));
	//TODO:
}

void AssignmentMenu::doAdd() {
	showOption(getName("a"));
	//TODO:
}

void AssignmentMenu::doEdit() {
	showOption(getName("e"));
	// TODO:
}

void AssignmentMenu::doRemove() {
	showOption(getName("r"));
	// TODO:
}

void AssignmentMenu::doSave() {
	showOption(getName("S"));
	// TODO:
}

void AssignmentMenu::activate() {
	char command = COMMAND::ADD;
	while (command != EXIT) {
		command = doMenuOption();
		switch (command) {
		case LIST:
			doList();
			break;
		case VIEW:
			doView();
			break;
		case ADD:
			doAdd();
			break;
		case EDIT:
			doEdit();
			break;
		case REMOVE:
			doRemove();
			break;
		case SAVE:
			doSave();
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

void AssignmentMenu::showOption(const string title) {
	cout << "***** " << title << " *****" << endl;
}
