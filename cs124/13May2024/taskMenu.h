/*******************************************************

 * Program Name: taskMenu.h

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program defines a TaskList class

 * Changes: 
    * 1. None - taken from Lab 4 template

 *******************************************************/

#pragma once
#include <fstream>
#include "menu.h"
#include "task.h"
#include "taskList.h"

using namespace std;

const string TASK_DATA = "task_data.csv";
enum COMMAND { ADD='a', EDIT='e', DELETE='d', PENDING = 'p', DONE = 'c', EXIT = 'x' };

class TaskMenu :public Menu {
public:
    TaskMenu();
    ~TaskMenu();

    void viewPendingTasks();
    void viewCompletedTasks();
    void addNewTask();
    void editTask();
    void deleteTask();
    void activate();

protected:
    void init();
    void showOption(string title);

private:
    fstream inFile;
    TaskList* list;
};
