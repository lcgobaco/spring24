/*******************************************************

 * Program Name: billing.h

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program defines a class that stores a patient's billing information.

 *******************************************************/

#ifndef H_BILLING
#define H_BILLING

#include <string>
#include "patient.h"

using namespace std;

class Billing {
private:
    Patient* patient;  // Pointer to the patient object
    double pharmacyCharges;
    double doctorFees;
    double roomCharges;

public:
    // Constructor
    Billing(Patient* patient, double pharmacyCharges, double doctorFees, double roomCharges);

    // Getter functions
    Patient* getPatient() const;
    double getPharmacyCharges() const { return pharmacyCharges; }
    double getDoctorFees() const { return doctorFees; }
    double getRoomCharges() const { return roomCharges; }

    // Setter functions
    void setPatient(Patient* patient) { this->patient = patient; }
    void setPharmacyCharges(double pharmacyCharges) { this->pharmacyCharges = pharmacyCharges; }
    void setDoctorFees(double doctorFees) { this->doctorFees = doctorFees; }
    void setRoomCharges(double roomCharges) { this->roomCharges = roomCharges; }
};

#endif