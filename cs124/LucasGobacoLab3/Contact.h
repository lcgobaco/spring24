/*******************************************************

 * Program Name: Contact.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a contact with a unique identifier, role, and company name.

 *******************************************************/

#ifndef CONTACT_H
#define CONTACT_H

#include "Person.h"

using namespace std;

class Contact : public Person {
private:
    string id;
    string role;
    string company_name;

public:
    /**
     * Constructs a contact with no unique identifier, role, or company name.
    */
    Contact();

    /**
     * Constructs a contact with a unique identifier, role, and company name.
     * @param id the unique identifier
     * @param first the first name
     * @param middle the middle name
     * @param last the last name
     * @param addr the address
     * @param cty the city
     * @param cnty the county
     * @param st the state
     * @param zp the zip code
     * @param ph1 the primary phone number
     * @param ph2 the secondary phone number
     * @param em the email
     * @param role the role
     * @param company_name the company name
    */
    Contact(string id, string first, string middle, string last, string addr, string cty, string cnty, string st, string zp, string ph1, string ph2, string em, string role, string company_name);

    /**
     * Destructs a contact.
    */
    ~Contact();

    /**
     * Returns the unique identifier of this contact.
     * @return the unique identifier
    */
    string getId() const;

    /**
     * Returns the role of this contact.
     * @return the role
    */
    string getRole() const;

    /**
     * Returns the company name of this contact.
     * @return the company name
    */
    string getCompanyName() const;

    /**
     * Sets the unique identifier of this contact.
     * @param id the unique identifier
    */
    void setId(string id);

    /**
     * Sets the role of this contact.
     * @param role the role
    */
    void setRole(string role);

    /**
     * Sets the company name of this contact.
     * @param company_name the company name
    */
    void setCompanyName(string company_name);
};

#endif