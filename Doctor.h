#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
using namespace std;

class Doctor {

public:

    int doctorID;
    string doctorName;
    string specialty;

    Doctor* left;
    Doctor* right;

    Doctor(int id, string name, string spec) {

        doctorID = id;
        doctorName = name;
        specialty = spec;

        left = NULL;
        right = NULL;
    }
};

#endif
