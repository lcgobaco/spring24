#pragma once
#include <string>
#include "task.h"
#include "hashtable.h"

using namespace std;

class TaskHashTable : public HashTable<Task> {

public:
	TaskHashTable(int nbuckets);
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
	bool contains(string name);
	Task get(string name);
	void remove(string name);
	vector<Task> values();
};
