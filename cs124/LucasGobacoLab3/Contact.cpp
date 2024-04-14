#include "Contact.h"

// Constructor definition
Contact::Contact(int id, std::string first, std::string middle, std::string last, DateTime dob, std::string addr, std::string cty, std::string cnty, std::string st, std::string zp, std::string ph1, std::string ph2, std::string pro, std::string em, std::string role, std::string company_name)
    : Person(first, middle, last, dob, addr, cty, cnty, st, zp, ph1, ph2, pro, em), id(id), role(role), company_name(company_name) {}

// Destructor definition
Contact::~Contact() {}

// Accessor function definitions
int Contact::getId() const { return id; }
std::string Contact::getRole() const { return role; }
std::string Contact::getCompanyName() const { return company_name; }

// Mutator function definitions
void Contact::setId(int id) { this->id = id; }
void Contact::setRole(std::string role) { this->role = role; }
void Contact::setCompanyName(std::string company_name) { this->company_name = company_name; }
