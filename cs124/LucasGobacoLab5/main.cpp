/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program contains the main function to test the classes.

 *******************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "assignment.h"
#include "faculty.h"
#include "gradeScale.h"
#include "section.h"
#include "assignmentMenu.h"

using namespace std;
int main() {

    AssignmentMenu menu;
    menu.activate();

//     cout << "Loading faculties..." << endl;
//    map<string, Faculty*> facultyMap = loadFaculties();
//    cout << "Finished loading faculties" << endl;

//    cout << "Loading sections..." << endl;
//    map<string, Section*> sectionMap = loadSections(facultyMap);
//    cout << "Finished loading sections" << endl;

//    cout << "Loading grade scales..." << endl;
//    map<int, GradeScale*> gradeScaleMap = loadGradeScales(sectionMap);
//    cout << "Finished loading grade scales" << endl;

//     cout << "Loading assignments..." << endl;
//     map<int, Assignment*> assignmentMap = loadAssignments(gradeScaleMap);
//     cout << "Finished loading assignments" << endl;


//     cout << "Traversion Faculty->Section->GradeScale->Assignment" << endl;
//    for (auto it = facultyMap.begin(); it != facultyMap.end(); ++it) {
//         vector<Section*> sections = it->second->getSections();
//         for (auto it2 = sections.begin(); it2 != sections.end(); ++it2) {
//             vector<GradeScale*> gradeScales = (*it2)->getGradeScales();
//             for (auto it3 = gradeScales.begin(); it3 != gradeScales.end(); ++it3) {
//                 vector<Assignment*> assignments = (*it3)->getAssignments();
//                 for (auto it4 = assignments.begin(); it4 != assignments.end(); ++it4) {
//                     cout << it->second->getFacultyId() << ",";
//                     cout << (*it2)->getSectionId() << ",";
//                     cout << (*it3)->getGradeScaleId() << ",";
//                     cout << (*it4)->getAssignmentId() << endl;
//                 }
//             }
//         }
//    }

//    AssignmentBST assignmentBST;
//     cout << "Traversion Assignment->GradeScale->Section->Faculty" << endl;
//     for (auto it = assignmentMap.begin(); it != assignmentMap.end(); ++it) {
//         assignmentBST.insert(it->second);
//         cout << it->second->getAssignmentId() << ",";
//         cout << it->second->getGradeScale()->getGradeScaleId() << ",";
//         cout << it->second->getGradeScale()->getSection()->getSectionId() << ",";
//         cout << it->second->getGradeScale()->getSection()->getFaculty()->getFacultyId() << endl;
//     }

//     for (auto it = assignmentMap.begin(); it != assignmentMap.end(); ++it) {
//         int count = assignmentBST.count(it->second);
//         cout << it->second->getAssignmentId() << "," << count << endl;
//      }


//     for (auto it = assignmentMap.begin(); it != assignmentMap.end(); ++it) {
//         assignmentBST.erase(it->second);
//         cout << it->second->getAssignmentId() << ",";
//         cout << it->second->getGradeScale()->getGradeScaleId() << ",";
//         cout << it->second->getGradeScale()->getSection()->getSectionId() << ",";
//         cout << it->second->getGradeScale()->getSection()->getFaculty()->getFacultyId() << endl;
//     }

//     for (auto it = assignmentMap.begin(); it != assignmentMap.end(); ++it) {
//         int count = assignmentBST.count(it->second);
//         cout << it->second->getAssignmentId() << "," << count << endl;
//      }

    return 0;
}
