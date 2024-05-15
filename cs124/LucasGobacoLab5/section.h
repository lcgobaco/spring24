#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <vector>

using namespace std;

class Faculty;

class GradeScale;

class Section {
private:
    string sectionId;
    string term;
    string courseName;
    int units;
    Faculty* faculty;
    vector<GradeScale*> gradeScales;

public:
    // Constructor
    Section(string id, const string& term, const string& courseName, int units, Faculty* faculty);

    Section();

    // Getter methods
    string getSectionId() const;
    string getTerm() const;
    string getCourseName() const;
    string getName() const;
    int getUnits() const;
    Faculty* getFaculty() const;
    vector<GradeScale*> getGradeScales() const;

    // Setter methods
    void setSectionId(string id);
    void setTerm(const string& t);
    void setCourseName(const string& c);
    void setUnits(int u);
    void setFaculty(Faculty* f);
    void setGradeScales(vector<GradeScale*> g);

    // Additional methods
    void addGradeScale(GradeScale* g);

    friend istream& operator>>(istream& in, Section&);
    friend ostream& operator<<(ostream& out, Section&);

};

#endif // SECTION_H
