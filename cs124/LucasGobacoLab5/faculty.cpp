/*******************************************************

 * Program Name: faculty.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores a faculty member's first name, last name, department, address, city, state, zip code, email, and phone number.

 *******************************************************/

#include "common.h"

Faculty::Faculty(string id, const string& fName, const string& lName,
    const string& dept, const string& addr,const   string& city,
    const string& state, const string& zip, const string& email,
    const string& phone)
    : facultyId(id), firstName(fName), lastName(lName), department(dept), address(addr), city(city), state(state), zip(zip), email(email), phone(phone) {}

string Faculty::getFacultyId() const { return facultyId; }

string Faculty::getFirstName() const { return firstName; }

string Faculty::getLastName() const { return lastName; }

string Faculty::getDepartment() const { return department; }

string Faculty::getAddress() const { return address; }

string Faculty::getCity() const { return city; }

string Faculty::getState() const { return state; }

string Faculty::getZip() const { return zip; }

string Faculty::getEmail() const { return email; }

string Faculty::getPhone() const { return phone; }

vector<Section> Faculty::getSections() const { return sections; }

void Faculty::setFacultyId(string id) { facultyId = id; }

void Faculty::setFirstName(const string& fName) { firstName = fName; }

void Faculty::setLastName(const string& lName) { lastName = lName; }

void Faculty::setDepartment(const string& dept) { department = dept; }

void Faculty::setAddress(const string& addr) { address = addr; }

void Faculty::setCity(const string& c) { city = c; }

void Faculty::setState(const string& s) { state = s; }

void Faculty::setZip(const string& z) { zip = z; }

void Faculty::setEmail(const string& e) { email = e; }

void Faculty::setPhone(const string& p) { phone = p; }

void Faculty::setSections(vector<Section> s) { sections = s; }
