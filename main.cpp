#include <iostream>
#include <queue>
#include <vector>
#include "Patient.h"

using namespace std;

int main() {

    Patient patients[100];
    int patientCount = 0;

    queue<int> patientQueue;

    priority_queue<int, vector<int>, greater<int>> emergencyQueue;

    int choice;

    while(true) {

        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Add Patient to Queue\n";
        cout << "4. Treat Next Patient\n";
        cout << "5. Add Emergency Patient\n";
        cout << "6. Treat Emergency Patient\n";
        cout << "7. Search Patient by ID\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:

                patients[patientCount].addPatient();
                patientCount++;

                break;

            case 2:

                if(patientCount == 0) {

                    cout << "No Patients Found!\n";
                }

                else {

                    for(int i = 0; i < patientCount; i++) {

                        cout << "\nPatient " << i + 1 << endl;

                        patients[i].displayPatient();
                    }
                }

                break;

            case 3:

                if(patientCount == 0) {

                    cout << "No patients available!\n";
                }

                else {

                    int patientNumber;

                    cout << "Enter Patient Number to Add to Queue: ";
                    cin >> patientNumber;

                    patientQueue.push(patientNumber - 1);

                    cout << "Patient added to queue successfully!\n";
                }

                break;

            case 4:

                if(patientQueue.empty()) {

                    cout << "No patients in queue!\n";
                }

                else {

                    int index = patientQueue.front();

                    cout << "\nTreating Patient:\n";

                    patients[index].displayPatient();

                    patientQueue.pop();
                }

                break;

            case 5:

                if(patientCount == 0) {

                    cout << "No patients available!\n";
                }

                else {

                    int emergencyPatient;

                    cout << "Enter Patient Number for Emergency: ";
                    cin >> emergencyPatient;

                    emergencyQueue.push(emergencyPatient - 1);

                    cout << "Emergency patient added successfully!\n";
                }

                break;

            case 6:

                if(emergencyQueue.empty()) {

                    cout << "No emergency patients!\n";
                }

                else {

                    int emergencyIndex = emergencyQueue.top();

                    cout << "\nTreating Emergency Patient:\n";

                    patients[emergencyIndex].displayPatient();

                    emergencyQueue.pop();
                }

                break;

            case 7: {

                int searchID;
                bool found = false;

                cout << "Enter Patient ID to Search: ";
                cin >> searchID;

                for(int i = 0; i < patientCount; i++) {

                    if(patients[i].id == searchID) {

                        cout << "\nPatient Found:\n";

                        patients[i].displayPatient();

                        found = true;

                        break;
                    }
                }

                if(!found) {

                    cout << "Patient Not Found!\n";
                }

                break;
            }

            case 8:

                cout << "Exiting Program...";
                return 0;

            default:

                cout << "Invalid Choice!";
        }
    }

    return 0;
}