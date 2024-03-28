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