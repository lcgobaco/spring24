/*******************************************************

 * Program Name: patient.h

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program defines a class that stores a patient's ID, age, date of birth, attending physician, admit date, and discharge date.

 *******************************************************/

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
    Patient() {
        // Default constructor
    }

    Patient(std::string id, int patientAge, DateType dob, Doctor physician, DateType admit, DateType discharge) {
        patientID = id;
        age = patientAge;
        dateOfBirth = dob;
        attendingPhysician = physician;
        admitDate = admit;
        dischargeDate = discharge;
    }

    // Accessors
    std::string getPatientID() const {
        return patientID;
    }

    int getAge() const {
        return age;
    }

    DateType getDateOfBirth() const {
        return dateOfBirth;
    }

    Doctor getAttendingPhysician() const {
        return attendingPhysician;
    }

    DateType getAdmitDate() const {
        return admitDate;
    }

    DateType getDischargeDate() const {
        return dischargeDate;
    }

    // Mutators
    void setPatientID(std::string id) {
        patientID = id;
    }

    void setAge(int patientAge) {
        age = patientAge;
    }

    void setDateOfBirth(DateType dob) {
        dateOfBirth = dob;
    }

    void setAttendingPhysician(Doctor physician) {
        attendingPhysician = physician;
    }

    void setAdmitDate(DateType admit) {
        admitDate = admit;
    }

    void setDischargeDate(DateType discharge) {
        dischargeDate = discharge;
    }

    // Input and Output operators
    friend std::istream& operator>>(std::istream& in, Patient& patient);
    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
};