/*******************************************************

 * Program Name: Person.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a person with a first name, middle name, last name, date of birth, address, city, county, state, zip code, phone number, pronouns, and email.

 *******************************************************/

#include "Person.h"

using namespace std;

Person::Person(string first, string middle, string last, DateTime* dob, string addr, string cty, string cnty, string st, string zp, string ph1, string ph2, string pro, string em)
    : first_name(first), middle_name(middle), last_name(last), birthdate(dob), address(addr), city(cty), county(cnty), state(st), zip(zp), phone1(ph1), phone2(ph2), pronouns(pro), email(em) {}

Person::Person() {}

Person::~Person() {}

string Person::getFirstName() const { return first_name; }

string Person::getMiddleName() const { return middle_name; }

string Person::getLastName() const { return last_name; }

DateTime Person::getBirthdate() const { return *birthdate; }

string Person::getAddress() const { return address; }

string Person::getCity() const { return city; }

string Person::getCounty() const { return county; }

string Person::getState() const { return state; }

string Person::getZip() const { return zip; }

string Person::getPhone1() const { return phone1; }

string Person::getPhone2() const { return phone2; }

string Person::getPronouns() const { return pronouns; }

string Person::getEmail() const { return email; }

void Person::setFirstName(string first) { first_name = first; }

void Person::setMiddleName(string middle) { middle_name = middle; }

void Person::setLastName(string last) { last_name = last; }

void Person::setBirthdate(DateTime* dob) { birthdate = dob; }

void Person::setAddress(string addr) { address = addr; }

void Person::setCity(string cty) { city = cty; }

void Person::setCounty(string cnty) { county = cnty; }

void Person::setState(string st) { state = st; }

void Person::setZip(string zp) { zip = zp; }

void Person::setPhone1(string ph1) { phone1 = ph1; }

void Person::setPhone2(string ph2) { phone2 = ph2; }

void Person::setPronouns(string pro) { pronouns = pro; }

void Person::setEmail(string em) { email = em; }