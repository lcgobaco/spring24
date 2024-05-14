/*******************************************************

 * Program Name: taskList.h

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program defines a TaskList class

 * Changes: 
    * 1. Changed all instance of "list" to "set"

 *******************************************************/

#pragma once
#include <string>
#include "task.h"
#include "linkedSet.h"

using namespace std;

class TaskList : public LinkedSet<Task> {

public:
	TaskList();
	~TaskList();

	void addNew();
	void editTask();
	void deleteTask();	
	void printTable(bool complete = true);

protected:
	void printRaw(bool complete = true);
	void printRow(const Task task);

private:
	void printHeader();
};