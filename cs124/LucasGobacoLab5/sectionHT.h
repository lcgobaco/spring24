#pragma once
#include <string>
#include "section.h"
#include "hashtable.h"

using namespace std;

class SectionHT : public HashTable<Section> {

public:
	SectionHT(int nbuckets);
	~SectionHT();

	void addNew();
	void editSection();
	void deleteSection();
	void printTable(bool complete = true);

protected:
	void printRaw(bool complete = true);
	void printRow(const Section Section);

private:
	void printHeader();
	bool contains(string name);
	Section get(string name);
	void remove(string name);
	vector<Section> values();
	int hash_code(Section* Section);
};
