#ifndef CONTACT_H
#define CONTACT_H

#include "Person.h"

class Contact : public Person {
private:
    int id;
    std::string role;
    std::string company_name;

public:
    // Constructor
    Contact(int id, std::string first, std::string middle, std::string last, DateTime dob, std::string addr, std::string cty, std::string cnty, std::string st, std::string zp, std::string ph1, std::string ph2, std::string pro, std::string em, std::string role, std::string company_name);

    // Destructor
    ~Contact();

    // Accessor functions
    int getId() const;
    std::string getRole() const;
    std::string getCompanyName() const;

    // Mutator functions
    void setId(int id);
    void setRole(std::string role);
    void setCompanyName(std::string company_name);
};

#endif // CONTACT_H
