/*******************************************************

 * Program Name: Person.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a person with a first name, middle name, last name, date of birth, address, city, county, state, zip code, phone number, pronouns, and email.

 *******************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "DateTime.h" 

using namespace std;

class Person {
private:
    string first_name;
    string middle_name;
    string last_name;
    DateTime* birthdate;
    string address;
    string city;
    string county;
    string state;
    string zip;
    string phone1;
    string phone2;
    string pronouns;
    string email;

public:
    /**
     * Constructs a person with no first name, middle name, last name, date of birth, address, city, county, state, zip code, phone number, pronouns, or email.
    */
    Person();

    /**
     * Constructs a person with a first name, middle name, last name, date of birth, address, city, county, state, zip code, phone number, pronouns, and email.
     * @param first the first name
     * @param middle the middle name
     * @param last the last name
     * @param dob the date of birth
     * @param addr the address
     * @param cty the city
     * @param cnty the county
     * @param st the state
     * @param zp the zip code
     * @param ph1 the primary phone number
     * @param ph2 the secondary phone number
     * @param pro the pronouns
     * @param em the email
    */
    Person(string first, string middle, string last, DateTime* dob, string addr, string cty, string cnty, string st, string zp, string ph1, string ph2, string pro, string em);
    
    /**
     * Destructs a person.
    */
    ~Person();

    /**
     * Returns the first name of this person.
     * @return the first name
    */
    string getFirstName() const;

    /**
     * Returns the middle name of this person.
     * @return the middle name
    */
    string getMiddleName() const;

    /**
     * Returns the last name of this person.
     * @return the last name
    */
    string getLastName() const;

    /**
     * Returns the date of birth of this person.
     * @return the date of birth
    */
    DateTime getBirthdate() const;

    /**
     * Returns the address of this person.
     * @return the address
    */
    string getAddress() const;

    /**
     * Returns the city of this person.
     * @return the city
    */
    string getCity() const;

    /**
     * Returns the county of this person.
     * @return the county
    */
    string getCounty() const;

    /**
     * Returns the state of this person.
     * @return the state
    */
    string getState() const;

    /**
     * Returns the zip code of this person.
     * @return the zip code
    */
    string getZip() const;

    /**
     * Returns the primary phone number of this person.
     * @return the primary phone number
    */
    string getPhone1() const;

    /**
     * Returns the secondary phone number of this person.
     * @return the secondary phone number
    */
    string getPhone2() const;

    /**
     * Returns the pronouns of this person.
     * @return the pronouns
    */
    string getPronouns() const;

    /**
     * Returns the email of this person.
     * @return the email
    */
    string getEmail() const;

    /**
     * Sets the first name of this person.
     * @param first the first name
    */
    void setFirstName(string first);

    /**
     * Sets the middle name of this person.
     * @param middle the middle name
    */
    void setMiddleName(string middle);

    /**
     * Sets the last name of this person.
     * @param last the last name
    */
    void setLastName(string last);

    /**
     * Sets the date of birth of this person.
     * @param dob the date of birth
    */
    void setBirthdate(DateTime* dob);

    /**
     * Sets the address of this person.
     * @param addr the address
    */
    void setAddress(string addr);

    /**
     * Sets the city of this person.
     * @param cty the city
    */
    void setCity(string cty);

    /**
     * Sets the county of this person.
     * @param cnty the county
    */
    void setCounty(string cnty);

    /**
     * Sets the state of this person.
     * @param st the state
    */
    void setState(string st);

    /**
     * Sets the zip code of this person.
     * @param zp the zip code
    */
    void setZip(string zp);

    /**
     * Sets the primary phone number of this person.
     * @param ph1 the primary phone number
    */
    void setPhone1(string ph1);

    /**
     * Sets the secondary phone number of this person.
     * @param ph2 the secondary phone number
    */
    void setPhone2(string ph2);

    /**
     * Sets the pronouns of this person.
     * @param pro the pronouns
    */
    void setPronouns(string pro);

    /**
     * Sets the email of this person.
     * @param em the email
    */
    void setEmail(string em);
};

#endif 