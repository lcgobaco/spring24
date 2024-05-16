#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <vector>

using namespace std;
class Section;

class Faculty {
private:
    string facultyId;
    string firstName;
    string lastName;
    string department;
    string address;
    string city;
    string state;
    string zip;
    string email;
    string phone;
    vector<Section*> sections;

public:
    // Constructor
    Faculty(string id, const string& fName, const string& lName,
        const string& dept, const string& addr, const string& city,
        const string& state, const string& zip, const string& email,
        const string& phone);

    Faculty();

    // Getter methods
    string getFacultyId() const;
    string getName() const;
    string getFirstName() const;
    string getLastName() const;
    string getDepartment() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;
    string getEmail() const;
    string getPhone() const;
    vector<Section*> getSections() const;

    // Setter methods
    void setFacultyId(string id);
    void setFirstName(const string& fName);
    void setLastName(const string& lName);
    void setDepartment(const string& dept);
    void setAddress(const string& addr);
    void setCity(const string& c);
    void setState(const string& s);
    void setZip(const string& z);
    void setEmail(const string& e);
    void setPhone(const string& p);
    void setSections(vector<Section*> s);

    // Additional methods
    void addSection(Section* section);

    friend istream& operator>>(istream& in, Faculty& faculty);
    friend ostream& operator<<(ostream& out, Faculty& faculty);
    bool operator==(const Faculty&);
};

#endif // FACULTY_H
