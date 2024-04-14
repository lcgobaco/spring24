/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 27 March 2024

 * Description: This program implements a hospital billing system.

 *******************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "billing.h"

using namespace std;

vector<Billing> billings;

// Function to display the program banner
void displayBanner() {
    cout << "****************************************************" << endl;
    cout << "     Program written by: Lucas Gobaco" << endl;
    cout << "     Description: The Hospital Billing System" << endl;
    cout << "     Course info: CS-124-03" << endl;
    cout << "     Term: Spring 2024" << endl;
    cout << "     Date: 27 March 2024" << endl;
    cout << "****************************************************" << endl;
}

// Function to display the main menu
void displayMainMenu() {
    cout << "***** The Hospital Billing System *****" << endl;
    cout << "1) Add Patient" << endl;
    cout << "2) Display all Patients" << endl;
    cout << "x) Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    displayBanner();

    char choice;
    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case '1':
            {
                // Add Patient
                Billing billing;
                cin >> billing;
                billings.push_back(billing);
            }
            case '2':
                // Display all Patients
                for (Billing b : billings) {
                    cout << b << endl;
                }
                break;
            case 'x':
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 'x');

    return 0;
}