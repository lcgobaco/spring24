#ifndef CONTACT_H
#define CONTACT_H

#include "Person.h"

class Contact : public Person {
private:
    string id;
    std::string role;
    std::string company_name;

public:
    // Constructor
    Contact(string id,
    std::string first, std::string middle, std::string last,
    std::string addr, std::string cty, std::string cnty, std::string st, std::string zp,
    std::string ph1, std::string ph2, std::string em,
    std::string role, std::string company_name);
    Contact();

    // Destructor
    ~Contact();

    // Accessor functions
    string getId() const;
    std::string getRole() const;
    std::string getCompanyName() const;

    // Mutator functions
    void setId(string id);
    void setRole(std::string role);
    void setCompanyName(std::string company_name);
};

#endif // CONTACT_H
