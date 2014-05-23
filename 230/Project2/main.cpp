/* 
 * File:   main.cpp
 * Author: Instinct
 *
 * Created on February 7, 2014, 4:56 PM
 */

#include "PatientType.h"
#include "LinkedListType.h"
//#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    void displayMenu();

    LinkedListType<PatientType> ER;

    displayMenu();
    char choice;
    cin >> choice;
    while (choice != 'Q') {
        switch (choice) {
            case 'E':
            {
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

                ER.addNode(PatientType(fName, lName, insurance, priority, arrivalTimeHr, arrivalTimeMin));
                cout << "**********NEW PATIENT ENTERED**********" << endl;
                break;
            }
            case 'N':
            {
                if (!ER.isEmpty()) {
                    PatientType *patient = new PatientType();
                    ER.remove(patient);
                    cout << endl << "Next patient is: " << (*patient).getfName()
                            << " " << (*patient).getlName() << endl
                            << "With priority level: " << (*patient).getPriority()
                            << endl;
                    delete patient;
                } else {
                    cout << endl << "Patient list is empty." << endl;
                }
                break;
            }
            case 'P':
            {
                if (ER.isEmpty()) {
                    cout << endl << "Patient list is empty." << endl;
                } else {
                    string lName, fName;
                    cout << endl << "Enter patient name (last name [space] first name): ";
                    cin >> lName >> fName;
                    NodeType<PatientType> *patientIterate;
                    PatientType *patientToCheck = new PatientType();
                    int pos = 0;
                    bool found = false;
                    while ((patientIterate != NULL) && !found) {
                        ER.findPosition(patientIterate, patientToCheck, pos);
                        if (((*patientToCheck).getfName() == fName) && ((*patientToCheck).getlName() == lName)) {
                            found = true;
                        }
                        pos++;
                    }
                    if (!found) {
                        cout << endl << "Patient is not in list." << endl;
                    } else {
                        string suffix;
                        if (pos == 1)
                            suffix = "st";
                        else if (pos == 2)
                            suffix = "nd";
                        else if (pos == 3)
                            suffix = "rd";
                        else
                            suffix = "th";
                        cout << endl << fName << " " << lName << " is " << pos << suffix << " in line." << endl;
                    }
                }
                break;
            }
            case 'D':
            {
                cout.setf(ios::left);
                cout << endl << setw(20) << "Last Name" << setw(15) << "First Name"
                        << setw(10) << "Priority" << setw(10) << "Arrival Time" << endl;
                NodeType<PatientType> *printer;
                PatientType *patientToPrint = new PatientType();
                if (ER.isEmpty()) {
                    cout << endl << "Patient list is empty." << endl;
                } else {
                    int pos = 0;
                    ER.iterate(printer, patientToPrint, pos);
                    while (printer != NULL) {
                        pos++;
                        PatientType::printPatient(*patientToPrint);
                        ER.iterate(printer, patientToPrint, pos);
                    }
                }
                delete patientToPrint;
                break;
            }
            default:
                cout << endl << "Invalid choice." << endl;
                break;
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