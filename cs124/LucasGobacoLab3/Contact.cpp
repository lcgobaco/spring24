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