/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#pragma once
#include <fstream>
#include "menu.h"

using namespace std;

enum COMMAND { LIST='l', VIEW='v', ADD='a', EDIT = 'e', REMOVE = 'r', SAVE = 's', EXIT = 'x' };

class AssignmentMenu :public Menu {
public:
    AssignmentMenu();
    ~AssignmentMenu();

    /*
doList - display all data from the root of the tree.
doView - view individual assignment and view group of assignments in rows and columns
doAdd - add to tree.
doEdit - edit any fields
doRemove - remove a node from the tree
calculateGrade - Implement your grade and display.
doSave - save data to .csv file
*/

    void doList();
    void doView();
    void doAdd();
    void doEdit();
    void doRemove();
    void doSave();
    void activate();

protected:
    void init();
    void showOption(string title);

private:
    fstream inFile;
};
