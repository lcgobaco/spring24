#ifndef GRADESCALE_H
#define GRADESCALE_H

#include<string>
#include<vector>

using namespace std;

class Section;
class Assignment;

class GradeScale {
private:
    string gradeScaleId;
    Section* section;
    string description;
    vector<Assignment*> assignments;
    double weight;

public:
    // Constructor
    GradeScale(string id, Section* section, const string& description, double weight);
    GradeScale();

    // Getter methods
    string getGradeScaleId() const;
    string getName() const;
    Section* getSection() const;
    string getDescription() const;
    vector<Assignment*> getAssignments() const;
    double getWeight() const;

    // Setter methods
    void setGradeScaleId(string id);
    void setSection(Section* s);
    void setDescription(const string& d);
    void setWeight(double w);
    void setAssignments(vector<Assignment*> a);
    void addAssignment(Assignment* assignment);

    friend istream& operator>>(istream& in, GradeScale&);
    friend ostream& operator<<(ostream& out, GradeScale&);

    bool operator==(const GradeScale& c);

};

#endif // GRADESCALE_H
