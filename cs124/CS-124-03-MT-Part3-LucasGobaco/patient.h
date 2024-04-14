/*******************************************************

 * Program Name: patient.h

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program defines a class that stores a patient's ID, age, date of birth, attending physician, admit date, and discharge date.

 *******************************************************/

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include "datetype.h"
#include "doctor.h"

class Patient : public Person {
private:
    std::string patientID;
    int age;
    DateType dateOfBirth;
    Doctor attendingPhysician;
    DateType admitDate;
    DateType dischargeDate;

public:
    // Constructors
    Patient();

    Patient(std::string id, int patientAge, DateType dob, Doctor physician, DateType admit, DateType discharge);

    // Accessors
    std::string getPatientID() const;

    int getAge() const;

    DateType getDateOfBirth() const;

    Doctor getAttendingPhysician() const;

    DateType getAdmitDate() const;

    DateType getDischargeDate() const;

    // Mutators
    void setPatientID(std::string id);

    void setAge(int patientAge);

    void setDateOfBirth(DateType dob);

    void setAttendingPhysician(Doctor physician);

    void setAdmitDate(DateType admit);

    void setDischargeDate(DateType discharge);

    // Input and Output operators
    friend std::istream& operator>>(std::istream& in, Patient& patient);
    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
};

#endif