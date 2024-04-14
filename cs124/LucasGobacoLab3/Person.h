#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "DateTime.h" // You would need to include the DateTime header file or replace it with your date/time handling implementation

class Person {
private:
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    DateTime birthdate; // Assuming DateTime class is declared in DateTime.h
    std::string address;
    std::string city;
    std::string county;
    std::string state;
    std::string zip;
    std::string phone1;
    std::string phone2;
    std::string pronouns;
    std::string email;

public:
    // Constructor
    Person(std::string first, std::string middle, std::string last, DateTime dob, std::string addr, std::string cty, std::string cnty, std::string st, std::string zp, std::string ph1, std::string ph2, std::string pro, std::string em);
    Person();
    // Destructor
    ~Person();

    // Accessor functions
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;
    DateTime getBirthdate() const;
    std::string getAddress() const;
    std::string getCity() const;
    std::string getCounty() const;
    std::string getState() const;
    std::string getZip() const;
    std::string getPhone1() const;
    std::string getPhone2() const;
    std::string getPronouns() const;
    std::string getEmail() const;

    // Mutator functions
    void setFirstName(std::string first);
    void setMiddleName(std::string middle);
    void setLastName(std::string last);
    void setBirthdate(DateTime dob);
    void setAddress(std::string addr);
    void setCity(std::string cty);
    void setCounty(std::string cnty);
    void setState(std::string st);
    void setZip(std::string zp);
    void setPhone1(std::string ph1);
    void setPhone2(std::string ph2);
    void setPronouns(std::string pro);
    void setEmail(std::string em);
};

#endif // PERSON_H
