#pragma once
#include <string>
#include "faculty.h"
#include "hashtable.h"

using namespace std;

class FacultyHT : public HashTable<Faculty> {

public:
	FacultyHT(int nbuckets);
	~FacultyHT();

	void addNew();
	void editFaculty();
	void deleteFaculty();
	void printTable(bool complete = true);

protected:
	void printRaw(bool complete = true);
	void printRow(const Faculty Faculty);

private:
	void printHeader();
	bool contains(string name);
	Faculty get(string name);
	void remove(string name);
	vector<Faculty> values();
	int hash_code(Faculty* Faculty);
};
