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
    Billing() : patient(nullptr), pharmacyCharges(0), doctorFees(0), roomCharges(0) {}
    Billing(Patient* patient, double pharmacyCharges, double doctorFees, double roomCharges);

    // Getter functions
    Patient* getPatient() const;
    double getPharmacyCharges() const;
    double getDoctorFees() const;
    double getRoomCharges() const;

    // Setter functions
    void setPatient(Patient* patient);
    void setPharmacyCharges(double pharmacyCharges);
    void setDoctorFees(double doctorFees);
    void setRoomCharges(double roomCharges);

    // Overloaded input/output operators
    friend istream& operator>>(istream& in, Billing& billing);
    friend ostream& operator<<(ostream& out, const Billing& billing);
};

#endif