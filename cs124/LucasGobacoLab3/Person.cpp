#include "Person.h"

// Constructor definition
Person::Person(std::string first, std::string middle, std::string last, DateTime dob, std::string addr, std::string cty, std::string cnty, std::string st, std::string zp, std::string ph1, std::string ph2, std::string pro, std::string em)
    : first_name(first), middle_name(middle), last_name(last), birthdate(dob), address(addr), city(cty), county(cnty), state(st), zip(zp), phone1(ph1), phone2(ph2), pronouns(pro), email(em) {}

// Destructor definition
Person::~Person() {}

// Accessor function definitions
std::string Person::getFirstName() const { return first_name; }
std::string Person::getMiddleName() const { return middle_name; }
std::string Person::getLastName() const { return last_name; }
DateTime Person::getBirthdate() const { return birthdate; }
std::string Person::getAddress() const { return address; }
std::string Person::getCity() const { return city; }
std::string Person::getCounty() const { return county; }
std::string Person::getState() const { return state; }
std::string Person::getZip() const { return zip; }
std::string Person::getPhone1() const { return phone1; }
std::string Person::getPhone2() const { return phone2; }
std::string Person::getPronouns() const { return pronouns; }
std::string Person::getEmail() const { return email; }

// Mutator function definitions
void Person::setFirstName(std::string first) { first_name = first; }
void Person::setMiddleName(std::string middle) { middle_name = middle; }
void Person::setLastName(std::string last) { last_name = last; }
void Person::setBirthdate(DateTime dob) { birthdate = dob; }
void Person::setAddress(std::string addr) { address = addr; }
void Person::setCity(std::string cty) { city = cty; }
void Person::setCounty(std::string cnty) { county = cnty; }
void Person::setState(std::string st) { state = st; }
void Person::setZip(std::string zp) { zip = zp; }
void Person::setPhone1(std::string ph1) { phone1 = ph1; }
void Person::setPhone2(std::string ph2) { phone2 = ph2; }
void Person::setPronouns(std::string pro) { pronouns = pro; }
void Person::setEmail(std::string em) { email = em; }
