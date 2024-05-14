/*******************************************************

 * Program Name: faculty.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that stores a faculty member's first name, last name, department, address, city, state, zip code, email, and phone number.

 *******************************************************/

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>

using namespace std;

class Faculty {
private:
    string facultyId;
    string firstName;
    string lastName;
    string department;
    string address;
    string city;
    string state;
    string zip;
    string email;
    string phone;

public:
    /**
     * Constructs a faculty object with a given ID, first name, last name, department, address, city, state, zip code, email, and phone number.
     * @param id the faculty ID
     * @param fName the faculty member's first name
     * @param lName the faculty member's last name
     * @param dept the faculty member's department
     * @param addr the faculty member's address
     * @param city the faculty member's city
     * @param state the faculty member's state
     * @param zip the faculty member's zip code
     * @param email the faculty member's email
     * @param phone the faculty member's phone number
    */
    Faculty(string id, const string& fName, const string& lName, const string& dept, const string& addr,const   string& city, const string& state, const   string& zip, const string& email, const string& phone);

    /**
     * Returns the faculty ID.
     * @return the faculty ID
    */
    string getFacultyId() const;

    /**
     * Returns the faculty member's first name.
     * @return the faculty member's first name
    */
    string getFirstName() const;

    /**
     * Returns the faculty member's last name.
     * @return the faculty member's last name
    */
    string getLastName() const;

    /**
     * Returns the faculty member's department.
     * @return the faculty member's department
    */
    string getDepartment() const;

    /**
     * Returns the faculty member's address.
     * @return the faculty member's address
    */
    string getAddress() const;

    /**
     * Returns the faculty member's city.
     * @return the faculty member's city
    */
    string getCity() const;

    /**
     * Returns the faculty member's state.
     * @return the faculty member's state
    */
    string getState() const;

    /**
     * Returns the faculty member's zip code.
     * @return the faculty member's zip code
    */
    string getZip() const;

    /**
     * Returns the faculty member's email.
     * @return the faculty member's email
    */
    string getEmail() const;

    /**
     * Returns the faculty member's phone number.
     * @return the faculty member's phone number
    */
    string getPhone() const;

    /**
     * Sets the faculty ID.
     * @param id the faculty ID
    */
    void setFacultyId(string id);

    /**
     * Sets the faculty member's first name.
     * @param fName the faculty member's first name
    */
    void setFirstName(const string& fName);

    /**
     * Sets the faculty member's last name.
     * @param lName the faculty member's last name
    */
    void setLastName(const string& lName);

    /**
     * Sets the faculty member's department.
     * @param dept the faculty member's department
    */
    void setDepartment(const string& dept);

    /**
     * Sets the faculty member's address.
     * @param addr the faculty member's address
    */
    void setAddress(const string& addr);

    /**
     * Sets the faculty member's city.
     * @param city the faculty member's city
    */
    void setCity(const string& city);

    /**
     * Sets the faculty member's state.
     * @param state the faculty member's state
    */
    void setState(const string& state);

    /**
     * Sets the faculty member's zip code.
     * @param zip the faculty member's zip code
    */
    void setZip(const string& zip);

    /**
     * Sets the faculty member's email.
     * @param email the faculty member's email
    */
    void setEmail(const string& email);

    /**
     * Sets the faculty member's phone number.
     * @param phone the faculty member's phone number
    */
    void setPhone(const string& phone);
};

#endif
