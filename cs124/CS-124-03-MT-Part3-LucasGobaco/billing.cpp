/*******************************************************

 * Program Name: billing.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a class that stores a patient's billing information.

 *******************************************************/

#include "billing.h"

// Constructor
Billing::Billing(Patient* patient, double pharmacyCharges, double doctorFees, double roomCharges)
    : patient(patient), pharmacyCharges(pharmacyCharges), doctorFees(doctorFees), roomCharges(roomCharges) {}

// Getter functions
Patient* Billing::getPatient() const {
    return patient;
}

double Billing::getPharmacyCharges() const {
    return pharmacyCharges;
}

double Billing::getDoctorFees() const {
    return doctorFees;
}

double Billing::getRoomCharges() const {
    return roomCharges;
}

// Setter functions
void Billing::setPatient(Patient* patient) {
    this->patient = patient;
}

void Billing::setPharmacyCharges(double pharmacyCharges) {
    this->pharmacyCharges = pharmacyCharges;
}

void Billing::setDoctorFees(double doctorFees) {
    this->doctorFees = doctorFees;
}

void Billing::setRoomCharges(double roomCharges) {
    this->roomCharges = roomCharges;
}

// Overloaded input/output operators
istream& operator>>(istream& in, Billing& billing) {
    Patient* patient = new Patient();
    in >> *patient >> billing.pharmacyCharges >> billing.doctorFees >> billing.roomCharges;
    billing.setPatient(patient);
    return in;
}

ostream& operator<<(ostream& out, const Billing& billing) {
    out << "Patient: " << *billing.getPatient() << endl;
    out << "Pharmacy Charges: $" << billing.getPharmacyCharges() << endl;
    out << "Doctor Fees: $" << billing.getDoctorFees() << endl;
    out << "Room Charges: $" << billing.getRoomCharges() << endl;
    return out;
}