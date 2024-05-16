/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#pragma once
#include <fstream>
#include "menu.h"
#include "facultyHT.h"
#include "gradeScaleHT.h"
#include "sectionHT.h"
#include "assignmentBST.h"

using namespace std;

enum COMMAND { LIST='l', VIEW='v', ADD='a', EDIT = 'e', REMOVE = 'r', SAVE = 's', EXIT = 'x' };

class AssignmentMenu :public Menu {
public:
    AssignmentMenu();
    ~AssignmentMenu();

    void doList();
    void doView();
    void doAdd();
    void doEdit();
    void doRemove();
    void doSave();
    void activate();

    FacultyHT* getFacultyHT();
    GradeScaleHT* getGradeScaleHT();
    SectionHT* getSectionHT();
    AssignmentBST* getAssignmentBST();

protected:
    void init();
    void test();
    void showOption(string title);

private:
    fstream inFile;
    FacultyHT* facultyHT;
    GradeScaleHT* gradeScaleHT;
    SectionHT* sectionHT;
    AssignmentBST* assignmentBST;

    // for debugging;
    map<string, Faculty*> fmap;
    map<string, Section*> smap;
    map<string, GradeScale*> gmap;
    map<string, Assignment*> amap;
};
