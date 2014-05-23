/* 
 * File:   main.cpp
 * Author: Instinct
 *
 * Created on February 11, 2014, 5:48 PM
 */
#include "queueType.h"
#include "serverType.h"
#include <fstream>
#include <functional>
#include <ctime>
#include <climits>
#include <iostream>
using namespace std;

typedef void(*Action)();

void iterateQueue(Action action) {
    action();
}

int main(int argc, char** argv) {
    void printServicedCustomer(ostream&, int&, int&, int&, int&);

    int simulationTime, coneTime, shakeTime, sundaeTime, currentTime = 0;
    int customerID = 1, totalWaitTime = 0, totalLineLength = 0, customersServiced = -1;
    int currentCustomerServiceTime;
    double arrivalProb;
    char commentary;

    cout << "Time-driven ice cream shop simulation" << endl
            << "Enter the following information to begin:" << endl << endl;
    cout << "Length of simulation (in minutes): ";
    cin >> simulationTime;
    cout << endl << "Probability of customer arrival each minute (example: 0.25): ";
    cin >> arrivalProb;
    cout << endl << "Minutes to make an ice cream cone: ";
    cin >> coneTime;
    cout << endl << "Minutes to make a shake: ";
    cin >> shakeTime;
    cout << endl << "Minutes to make a sundae: ";
    cin >> sundaeTime;
    cout << endl << "Commentary (Y/N): ";
    cin >> commentary;
    cout << endl << endl;

    QueueType<CustomerType> Line;
    serverType server;
    float chance;
    srand(time(0) % INT_MAX);
    ofstream newFile;
    newFile.open("C:/Documents and Settings/Instinct/Desktop/project3results.txt");

    while (currentTime < simulationTime) {
        chance = float (rand()) / RAND_MAX;
        if (chance < arrivalProb) {
            if (!Line.isFull()) {
                Line.addElement(CustomerType(currentTime, customerID));
                customerID++;
            } else {
                if ((commentary == 'Y') || (commentary == 'y')) {
                    cout << "Customer #" << customerID
                            << " came during a full line and left!" << endl;
                }
                newFile << "Customer #" << customerID
                        << " came during a full line and left!\r\n";
                customerID++;
            }
        }
        if (server.isFree() && (!Line.isEmpty())) {
            customersServiced++;
            if (customersServiced != 0) {
                if ((commentary == 'Y') || (commentary == 'y')) {
                    printServicedCustomer(cout, server.getCustomer().getID(),
                            server.getCustomer().getArrivalTime(), currentCustomerServiceTime,
                            server.getCustomer().getWaitTime());
                    cout << endl;
                }
                printServicedCustomer(newFile, server.getCustomer().getID(),
                        server.getCustomer().getArrivalTime(), currentCustomerServiceTime,
                        server.getCustomer().getWaitTime());
                newFile << "\r\n";
            }
            if (chance < 0.1) {
                currentCustomerServiceTime = shakeTime;
                server.setCustomer(Line.getFront(), currentCustomerServiceTime);
            } else if (chance < .4) {
                currentCustomerServiceTime = sundaeTime;
                server.setCustomer(Line.getFront(), currentCustomerServiceTime);
            } else {
                currentCustomerServiceTime = coneTime;
                server.setCustomer(Line.getFront(), currentCustomerServiceTime);
            }
            totalWaitTime += Line.getFront().getWaitTime();
            Line.removeElement();
        } else if (!server.isFree()) {
            server.decrementTransactionTime();
            for (CustomerType& cust : Line) {
                cust.incrementWaitTime();
            }
        }
        if ((commentary == 'Y') || (commentary == 'y')) {
            cout << "There are currently " << Line.getNumElements() << " people waiting in line." << endl;
        }
        newFile << "There are currently " << Line.getNumElements() << " people waiting in line." << "\r\n";
        totalLineLength += Line.getNumElements();
        currentTime++;
    }
    cout << endl << endl << "Simulation complete." << endl << endl;
    cout << "Total wait time: " << totalWaitTime << endl
            << "Customers serviced: " << customersServiced << endl
            << "Average wait time: " << float (totalWaitTime) / customersServiced << endl
            << "Average line length: " << float (totalLineLength) / simulationTime;
    newFile << "\r\nSimulation complete.\r\n";
    newFile << "Total wait time: " << totalWaitTime << "\r\n"
            << "Customers serviced: " << customersServiced << "\r\n"
            << "Average wait time: " << float (totalWaitTime) / customersServiced << "\r\n"
            << "Average line length: " << float (totalLineLength) / simulationTime;
    iterateQueue([] () {
        cout << endl << "I'm a lambda function!" << endl;
    });
    newFile.close();
    return 0;
}

void printServicedCustomer(ostream& os, int& ID, int& arrivalTime, int& serviceTime, int& waitTime) {
    os << "Customer #" << ID << " has been serviced. "
            << "They arrived at " << arrivalTime
            << " and their service took " << serviceTime << " minutes. "
            << "They waited in line for " << waitTime << " minutes.";
}