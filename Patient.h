#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;

    void addPatient() {
        cout << "Enter Patient ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Disease: ";
        getline(cin, disease);
    }

    void displayPatient() {
        cout << "\nPatient ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
    }
};

#endif