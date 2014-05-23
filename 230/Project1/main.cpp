/* 
 * File:   main.cpp
 * Author: Instinct
 *
 * Created on February 5, 2014, 4:20 PM
 */

#include "ArrayType.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    void displayMenu();

    ArrayType ER;

    char choice;
    displayMenu();
    cin >> choice;

    while (choice != 'Q') {
        switch (choice) {
            case 'E': {
                string fName, lName, insurance;
                int priority, arrivalTimeHr, arrivalTimeMin;
                cout << endl << "Enter new patient's last name: ";
                cin >> lName;
                cout << endl << "Enter new patient's first name: ";
                cin >> fName;
                cout << endl << "Enter new patient's insurance provider: ";
                cin >> insurance;
                cout << endl << "Enter new patient's priority: ";
                cin >> priority;
                cout << endl << "Enter the hour: ";
                cin >> arrivalTimeHr;
                cout << endl << "Enter the minute: ";
                cin >> arrivalTimeMin;

                PatientType newP(lName, fName, insurance, priority, arrivalTimeHr, arrivalTimeMin);
                ER.addPatient(newP);
                break;
            }
            case 'N': {
                cout << endl << "Next patient is: " << ER.nextPatient().getLastName() << ", " << ER.nextPatient().getFirstName()
                        << endl << "With priority level: " << ER.nextPatient().getPriority() << endl;
                ER.removePatient();
                break;
            }
            case 'P': {
                cout << endl << "Enter patient's full name (last name [space] first name): ";
                string lName, fName;
                cin >> lName >> fName;
                int pos = ER.findPosition(lName, fName);
                if (pos == -1) {
                    cout << endl << "Patient not found.";
                } else {
                    switch (pos) {
                        case 1:
                            cout << endl << "Patient is 1st in line." << endl;
                            break;
                        case 2:
                            cout << endl << "Patient is 2nd in line." << endl;
                            break;
                        case 3:
                            cout << endl << "Patient is 3rd in line." << endl;
                            break;
                        default:
                            cout << endl << "Patient is " << pos << "th in line." << endl;
                    }
                }
                break;
            }
            case 'D': {
                ER.printList();
                break;
            }
            default:
                cout << endl << "Invalid choice.";
        }
        displayMenu();
        cin >> choice;
    }
    return 0;
}

void displayMenu() {
    cout << endl << "Please select your option from the following menu:" << endl;
    cout << "E: Enter a new patient" << endl;
    cout << "N: Find next patient & remove him/her from the list" << endl;
    cout << "P: Determine the position of a specific patient" << endl;
    cout << "D: Print the list of patients" << endl;
    cout << "Q: Quit" << endl << endl;
    cout << "Enter your Choice: ";
}