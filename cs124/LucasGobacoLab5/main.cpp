/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program contains the main function to test the classes.

 *******************************************************/

#include <iostream>
#include <string>
#include "common.h"
#include "Utils.h"
#include <fstream>
#include <map>

using namespace std;

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
        GradeScale* gradeScale = new GradeScale(stoi(tokens[0]), section, tokens[2], stod(tokens[3]));
        gradeScales[stoi(tokens[0])] = gradeScale;
        section->addGradeScale(gradeScale);
    }

    return gradeScales;

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

        //Faculty faculty = new Faculty;
        Faculty* faculty = new Faculty(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9]);
        //faculties.insert(std::make_pair(tokens[0],&faculty));
        faculties[tokens[0]] = faculty;
    }

    return faculties;
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
int main() {

    cout << "Loading faculties..." << endl;
   map<string, Faculty*> facultyMap = loadFaculties();
   cout << "Finished loading faculties" << endl;

   cout << "Loading sections..." << endl;
   map<string, Section*> sectionMap = loadSections(facultyMap);
   cout << "Finished loading sections" << endl;

   cout << "Loading grade scales..." << endl;
   map<int, GradeScale*> gradeScaleMap = loadGradeScales(sectionMap);
   cout << "Finished loading grade scales" << endl;

    cout << "Loading assignments..." << endl;
    map<int, Assignment*> assignmentMap = loadAssignments(gradeScaleMap);
    cout << "Finished loading assignments" << endl;


    cout << "Traversion Faculty->Section->GradeScale->Assignment" << endl;
   for (auto it = facultyMap.begin(); it != facultyMap.end(); ++it) {
        vector<Section*> sections = it->second->getSections();
        for (auto it2 = sections.begin(); it2 != sections.end(); ++it2) {
            vector<GradeScale*> gradeScales = (*it2)->getGradeScales();
            for (auto it3 = gradeScales.begin(); it3 != gradeScales.end(); ++it3) {
                vector<Assignment*> assignments = (*it3)->getAssignments();
                for (auto it4 = assignments.begin(); it4 != assignments.end(); ++it4) {
                    cout << it->second->getFacultyId() << ",";
                    cout << (*it2)->getSectionId() << ",";
                    cout << (*it3)->getGradeScaleId() << ",";
                    cout << (*it4)->getAssignmentId() << endl;
                }
            }
        }
   }
    cout << "Traversion Assignment->GradeScale->Section->Faculty" << endl;
        for (auto it = assignmentMap.begin(); it != assignmentMap.end(); ++it) {
        cout << it->second->getAssignmentId() << ",";
        cout << it->second->getGradeScale()->getGradeScaleId() << ",";
        cout << it->second->getGradeScale()->getSection()->getSectionId() << ",";
        cout << it->second->getGradeScale()->getSection()->getFaculty()->getFacultyId() << endl;
    }

    return 0;
}
