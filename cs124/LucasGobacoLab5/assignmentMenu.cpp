/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "assignment.h"
#include "faculty.h"
#include "gradeScale.h"
#include "section.h"
#include "assignmentMenu.h"
#include "Utils.h"

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
	addOption("x", "Exit");

    facultyHT = new FacultyHT(100);
    gradeScaleHT = new GradeScaleHT(100);
    sectionHT = new SectionHT(100);
    assignmentBST = new AssignmentBST();
	init();
}

map<string, Faculty*> loadFaculties();

AssignmentMenu::~AssignmentMenu() {
	delete facultyHT;
	delete gradeScaleHT;
	delete sectionHT;
	delete assignmentBST;
	inFile.close();
}

void AssignmentMenu::init(){
	map<string, Faculty*> fmap = loadFaculties();
	for (auto it = fmap.begin(); it != fmap.end(); ++it) {
		facultyHT->insert(it->second);
	}
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

map<string, Faculty*> loadFaculties() {
    ifstream inFile;
    inFile.open("faculty-data.csv");
    if (!inFile) {
        cerr << "Unable to open file faculty-data.csv";
        exit(1);   // call system to stop
    }

    map<string, Faculty*> faculties;
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        vector<string> tokens = splitString(line, ',');

        Faculty* faculty = new Faculty(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9]);
        faculties[tokens[0]] = faculty;
    }

    return faculties;
}

map<string, Section*> loadSections(map<string, Faculty*> facultyMap) {
    ifstream inFile;
    inFile.open("section-data.csv");
    if (!inFile) {
        cerr << "Unable to open file section-data.csv";
        exit(1);   // call system to stop
    }

    map<string, Section*> sections;
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        vector<string> tokens = splitString(line, ',');
        string facultyId = tokens[4];

        Faculty* faculty = facultyMap[facultyId];
        Section* section = new Section(tokens[1], tokens[0], tokens[2], stoi(tokens[3]), faculty);
        sections[tokens[1]] = section;
        faculty->addSection(section);
    }

    return sections;
}

map<int, GradeScale*> loadGradeScales(map<string, Section*> sectionMap) {
    ifstream inFile;
    inFile.open("grade-scale-data.csv");
    if (!inFile) {
        cerr << "Unable to open file grade-scale-data.csv";
        exit(1);   // call system to stop
    }

    map<int, GradeScale*> gradeScales;
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        vector<string> tokens = splitString(line, ',');
        Section* section = sectionMap[tokens[1]];
        GradeScale* gradeScale = new GradeScale(tokens[0], section, tokens[2], stod(tokens[3]));
        gradeScales[stoi(tokens[0])] = gradeScale;
        section->addGradeScale(gradeScale);
    }

    return gradeScales;

}


map<int, Assignment*> loadAssignments(map<int, GradeScale*> gradeScaleMap) {
    ifstream inFile;
    inFile.open("assignment-data.csv");
    if (!inFile) {
        cerr << "Unable to open file assignment-data.csv";
        exit(1);   // call system to stop
    }

    map<int, Assignment*> assignments;;
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        vector<string> tokens = splitString(line, ',');
        GradeScale* gradeScale = gradeScaleMap[stoi(tokens[1])];
        Assignment* assignment = new Assignment(stoi(tokens[0]), gradeScale, tokens[2], tokens[3], tokens[4], stod(tokens[5]), stod(tokens[6]));
        assignments[stoi(tokens[0])] = assignment;
        gradeScale->addAssignment(assignment);
    }
    inFile.close();
    return assignments;
}
