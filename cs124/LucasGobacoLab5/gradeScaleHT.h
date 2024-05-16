#pragma once
#include <string>
#include "gradeScale.h"
#include "hashtable.h"

using namespace std;

class GradeScaleHT : public HashTable<GradeScale*> {
	public:
		GradeScaleHT(int nbuckets);
		~GradeScaleHT();

		void addNew();
		void editGradeScale();
		void deleteGradeScale();
		void printTable();
		GradeScale* findById(string id);
		vector<GradeScale*> values();

	protected:
		void printRow(const GradeScale* GradeScale);

	private:
		void printHeader();
		bool contains(string name);
		GradeScale* get(string name);
		void remove(string name);
		int hash_code(GradeScale* GradeScale);
};
