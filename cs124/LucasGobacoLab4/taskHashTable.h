#pragma once
#include <string>
#include "task.h"
#include "hashtable.h"

using namespace std;

class TaskHashTable : public HashTable<string, Task> {

public:
	TaskHashTable();
	~TaskHashTable();

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
