/*******************************************************

 * Program Name: patient.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a class that stores a patient's ID, age, date of birth, attending physician, admit date, and discharge date.

 *******************************************************/

#include "patient.h"

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