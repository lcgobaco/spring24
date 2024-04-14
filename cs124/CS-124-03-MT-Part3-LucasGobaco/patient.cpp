/*******************************************************

 * Program Name: patient.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a class that stores a patient's ID, age, date of birth, attending physician, admit date, and discharge date.

 *******************************************************/

#include "patient.h"

// Accessors
std::string Patient::getPatientID() const {
    return patientID;
}

int Patient::getAge() const {
    return age;
}

DateType Patient::getDateOfBirth() const {
    return dateOfBirth;
}

Doctor Patient::getAttendingPhysician() const {
    return attendingPhysician;
}

DateType Patient::getAdmitDate() const {
    return admitDate;
}

DateType Patient::getDischargeDate() const {
    return dischargeDate;
}

// Mutators
void Patient::setPatientID(std::string id) {
    patientID = id;
}

void Patient::setAge(int patientAge) {
    age = patientAge;
}

void Patient::setDateOfBirth(DateType dob) {
    dateOfBirth = dob;
}

void Patient::setAttendingPhysician(Doctor physician) {
    attendingPhysician = physician;
}

void Patient::setAdmitDate(DateType admit) {
    admitDate = admit;
}

void Patient::setDischargeDate(DateType discharge) {
    dischargeDate = discharge;
}

// Overloaded input/output operators
std::istream& operator>>(std::istream& in, Patient& patient) {
    // Read patient details from input stream
    in >> patient.patientID >> patient.age >> patient.dateOfBirth >> patient.attendingPhysician >> patient.admitDate >> patient.dischargeDate;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    // Write patient details to output stream
    out << "Patient ID: " << patient.patientID << std::endl;
    out << "Age: " << patient.age << std::endl;
    out << "Date of Birth: " << patient.dateOfBirth << std::endl;
    out << "Attending Physician: " << patient.attendingPhysician << std::endl;
    out << "Admit Date: " << patient.admitDate << std::endl;
    out << "Discharge Date: " << patient.dischargeDate << std::endl;
    return out;
}