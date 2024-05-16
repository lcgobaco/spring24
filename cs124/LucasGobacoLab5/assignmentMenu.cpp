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

const string ASSIGNMENT_FILE = "assignment-data.csv";

AssignmentMenu::AssignmentMenu() : Menu("Main Menu") {
	addOption("l", "List Assignments");
	addOption("v", "View Assignment");
	addOption("a", "Add Assignment");
	addOption("e", "Edit Assignment");
	addOption("r", "Remove Assignment");
	addOption("c", "Calculate Grade");
	addOption("g", "View Grade Scale");
	addOption("s", "Save");
	addOption("x", "Exit");

    facultyHT = new FacultyHT(100);
    gradeScaleHT = new GradeScaleHT(100);
    sectionHT = new SectionHT(100);
    assignmentBST = new AssignmentBST();
	init();
}

// Forward declarations
map<string, Faculty*> loadFaculties();
map<string, Section*> loadSections(map<string, Faculty*> facultyMap);
map<string, GradeScale*> loadGradeScales(map<string, Section*> sectionMap);
map<string, Assignment*> loadAssignments(map<string, GradeScale*> gradeScaleMap);
void test();

AssignmentMenu::~AssignmentMenu() {
	delete facultyHT;
	delete gradeScaleHT;
	delete sectionHT;
	delete assignmentBST;
	inFile.close();
}


void AssignmentMenu::init(){
	load();
}

void AssignmentMenu::doList() {
	showOption(getName("l"));
	cout << assignmentBST->size() << " assignments found." << endl;
	assignmentBST->list();
}

void AssignmentMenu::doView() {
	showOption(getName("v"));
	cout << "Enter the assignment ID: ";
	string id;
	cin >> id;

	Assignment assignment = assignmentBST->findById(id);
	if (assignment.getAssignmentId() == "") {
		cout << "Assignment not found." << endl;
		return;
	}

	cout << assignment;
}

void AssignmentMenu::doAdd() {
	showOption(getName("a"));
	Assignment* assignment = new Assignment();
	cin >> *assignment;
	cout << "Enter Grade Scale ID: ";
	string gradeScaleId;
	cin >> gradeScaleId;
	GradeScale* gradeScale = gradeScaleHT->findById(gradeScaleId);
	if (gradeScale == nullptr) {
		cout << "Grade Scale not found." << endl;
		return;
	}
	assignment->setGradeScale(gradeScale);
	cout << assignment;

	assignmentBST->insert(assignment);
	amap[assignment->getAssignmentId()] = assignment;
}

void AssignmentMenu::doEdit() {
	showOption(getName("e"));
	cout << "Enter the assignment ID: ";
	string id;
	cin >> id;
	Assignment assignment = assignmentBST->findById(id);
	if (assignment.getAssignmentId() == "") {
		cout << "Assignment not found." << endl;
		return;
	}

	Assignment* newAssignment = new Assignment();
	newAssignment->setAssignmentId(assignment.getAssignmentId());

	cout << "Enter the new description (" << assignment.getDescription() << "): ";
	string description;
	cin.ignore();
	getline(cin, description);
	if (description == "") {
		description = assignment.getDescription();
	}
	newAssignment->setDescription(description);
	cout << "Enter the new start date (" << assignment.getStartDate() << "): ";
	string startDate;
	cin.ignore();
	getline(cin, startDate);
	if (startDate == "") {
		startDate = assignment.getStartDate();
	}
	newAssignment->setStartDate(startDate);
	cout << "Enter the new end date (" << assignment.getEndDate() << "):";
	string endDate;
	cin.ignore();
	getline(cin, endDate);
	if (endDate == "") {
		endDate = assignment.getEndDate();
	}
	newAssignment->setEndDate(endDate);
	cout << "Enter the new possible points (" << assignment.getPossiblePoints() << "): ";
	double possiblePoints;
	cin >> possiblePoints;
	if (possiblePoints == 0) {
		possiblePoints = assignment.getPossiblePoints();
	}
	newAssignment->setPossiblePoints(possiblePoints);
	cout << "Enter the new points (" << assignment.getPoints() << "): ";
	double points;
	cin >> points;
	if (points == 0) {
		points = assignment.getPoints();
	}
	newAssignment->setPoints(points);
	cout << "Enter the Grade Scale ID (" << assignment.getGradeScale()->getGradeScaleId() << "): ";
	string gradeScaleId;
	cin >> gradeScaleId;
	if (gradeScaleId == "") {
		gradeScaleId = assignment.getGradeScale()->getGradeScaleId();
	}
	GradeScale* gradeScale = gradeScaleHT->findById(gradeScaleId);
	if (gradeScale == nullptr) {
		cout << "Grade Scale not found." << endl;
	}
	newAssignment->setGradeScale(gradeScale);

	assignmentBST->erase(&assignment);
	assignmentBST->insert(newAssignment);
	amap[newAssignment->getAssignmentId()] = newAssignment;
}

void AssignmentMenu::doRemove() {
	showOption(getName("r"));
	cout << "Enter the assignment ID: ";
	string id;
	cin >> id;

	Assignment assignment = assignmentBST->findById(id);
	if (assignment.getAssignmentId() == "") {
		cout << "Assignment not found." << endl;
		return;
	}
	assignmentBST->erase(&assignment);
	amap.erase(assignment.getAssignmentId());
	cout << "Assignment removed." << endl;
}

void AssignmentMenu::doSave() {
	showOption(getName("s"));

	assignmentBST->save(ASSIGNMENT_FILE);

}

void AssignmentMenu::doGradeScale() {
	showOption(getName("g"));
	gradeScaleHT->printTable();
}


	/**
 To calculate the percentage of each group multiply by its weight (percentage)
 and add all the groups together,
 then divide by the sum of the weights.
To calculate the percentage of each group, the sum of the total points divided by the possible points multiplied by 100.

grade_scale -> assignment
                - points
                - possible points*/
void AssignmentMenu::doCalculate() {
	showOption(getName("c"));

	double grade = 0.0;

	map<string, int> gradeScalePossiblePoints;
	map<string, double> gradeScalePoints;

	vector<Assignment>* assignments = assignmentBST->values();
	for (int i = 0; i < assignments->size(); i++) {
		Assignment assignment = assignments->at(i);
		gradeScalePossiblePoints[assignment.getGradeScale()->getGradeScaleId()] += assignment.getPossiblePoints();
		gradeScalePoints[assignment.getGradeScale()->getGradeScaleId()] += assignment.getPoints();
	}

	// loop thru gradeScalePossiblePoints
	for (auto const& value : gradeScalePossiblePoints) {
		string gradeScaleId = value.first;
		double possiblePoints = gradeScalePossiblePoints[gradeScaleId];
		double points = gradeScalePoints[gradeScaleId];
		double percentage = (points / possiblePoints);
		GradeScale* gradeScale = gradeScaleHT->findById(gradeScaleId);
		grade += gradeScale->getWeight() * percentage;
	}

	cout << "Grade: " << grade << "%" << endl;
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
		case CALCULATE:
			doCalculate();
			break;
		case GRADE_SCALE:
			doGradeScale();
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

	inFile.close();
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

	inFile.close();

    return sections;
}

map<string, GradeScale*> loadGradeScales(map<string, Section*> sectionMap) {
    ifstream inFile;
    inFile.open("grade-scale-data.csv");
    if (!inFile) {
        cerr << "Unable to open file grade-scale-data.csv";
        exit(1);   // call system to stop
    }

    map<string, GradeScale*> gradeScales;
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        vector<string> tokens = splitString(line, ',');
        Section* section = sectionMap[tokens[1]];
        GradeScale* gradeScale = new GradeScale(tokens[0], section, tokens[2], stod(tokens[3]));
        gradeScales[tokens[0]] = gradeScale;
        section->addGradeScale(gradeScale);
    }

	inFile.close();
    return gradeScales;
}


map<string, Assignment*> loadAssignments(string filename, map<string, GradeScale*> gradeScaleMap) {
    ifstream inFile;
    inFile.open(filename);
    if (!inFile) {
        cerr << "Unable to open file assignment-data.csv";
        exit(1);   // call system to stop
    }

    map<string, Assignment*> assignments;;
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        vector<string> tokens = splitString(line, ',');
        GradeScale* gradeScale = gradeScaleMap[tokens[1]];
        Assignment* assignment = new Assignment(tokens[0], gradeScale, tokens[2], tokens[3], tokens[4], stod(tokens[5]), stod(tokens[6]));
        assignments[tokens[0]] = assignment;
        gradeScale->addAssignment(assignment);
    }
    inFile.close();
    return assignments;
}

void AssignmentMenu::load() {

	// Load from file in Faculty Hash Table
	fmap = loadFaculties();
	for (auto it = fmap.begin(); it != fmap.end(); ++it) {
	 	Faculty* faculty = it->second;
	 	facultyHT->insert(faculty);
	}

	// Load from file into Section Hash Table
	smap = loadSections(fmap);
	for (auto it = smap.begin(); it != smap.end(); ++it) {
		Section* section = it->second;
		sectionHT->insert(section);
	}

	// Load from file into GradeScale Hash Table
	gmap = loadGradeScales(smap);
	for (auto it = gmap.begin(); it != gmap.end(); ++it) {
		GradeScale* gradeScale = it->second;
		gradeScaleHT->insert(gradeScale);
	}

	// Load from file into Assignment Binary Search Tree
	amap = loadAssignments(ASSIGNMENT_FILE, gmap);
	for (auto it = amap.begin(); it != amap.end(); ++it) {
	 	Assignment* assignment = it->second;
	 	assignmentBST->insert(assignment);
	}
}
