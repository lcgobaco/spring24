/*******************************************************

 * Program Name: doctor.h

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program defines a class that stores a doctor's first and last name and specialty.

 *******************************************************/

#ifndef H_DOCTOR
#define H_DOCTOR

#include <string>
#include "person.h"

using namespace std;

class Doctor : public Person {
public:

    //constructor
    Doctor(string first = "", string last = "", string specialty = "");

    //getter for specialty
    string getSpecialty() const;

    //setter for specialty
    void setSpecialty(string specialty);

    //input operator
    friend istream& operator>>(istream& in, Doctor& doctor);

    //output operator
    friend ostream& operator<<(ostream& out, const Doctor& doctor);

private:    
    string specialty; //variable to store the specialty
};

#endif