/*******************************************************

 * Program Name: Contact.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a class that defines a contact with a unique identifier, role, and company name.

 *******************************************************/

#include "Contact.h"

using namespace std;

Contact::Contact(string id, string first, string middle, string last, string addr, string cty, string cnty, string st, string zp, string ph1, string ph2, string em, string role, string company_name)
    : Person(first, middle, last, nullptr, addr, cty, cnty, st, zp, ph1, ph2, "", em), id(id), role(role), company_name(company_name) {}

Contact::Contact() {};

Contact::~Contact() {}

string Contact::getId() const { return id; }

string Contact::getRole() const { return role; }

string Contact::getCompanyName() const { return company_name; }

void Contact::setId(string id) { this->id = id; }

void Contact::setRole(string role) { this->role = role; }

void Contact::setCompanyName(string company_name) { this->company_name = company_name; }

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    // Stream out the relevant attributes of the Contact object
    os << contact.getId() << ","
             << contact.getFirstName() << ","
             << contact.getMiddleName() << ","
             << contact.getLastName() << ","
             << contact.getRole() << ","
             << contact.getCompanyName() << ","
             << contact.getAddress() << ","
             << contact.getCity() << ","
             << contact.getCounty() << ","
             << contact.getState() << ","
             << contact.getZip() << ","
             << contact.getPhone1() << ","
             << contact.getPhone2() << ","
             << contact.getEmail();

    return os;
}

string Contact::sortByField = "id";

bool Contact::operator==(const Contact& c) {
	return this->getId() == c.getId();

}
bool Contact::operator>(const Contact& c) {
	return this->getId() > c.getId();
}

bool Contact::operator<(const Contact& c) {
	return this->getId() < c.getId();;
}
