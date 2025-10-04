#include "Surgery.h"
#include <iostream>
#include <iomanip>

using namespace std;

Surgery::Surgery() {
    surgeryNames = {"Appendectomy", "Bypass Surgery", "Cataract Removal", 
    "Hip Replacement", "Tonsillectomy"};
    surgeryCharges = {5000.0, 15000.0, 4000.0, 12000.0, 3000.0};
}

void Surgery::list() const {
    cout << "\nAvailable Surgeries:" << endl;
    cout << left << setw(5) << "ID" << setw(25) << "Surgery" << "Price" << endl;
    cout << "-----------------------------------" << endl;
    
    for (size_t i = 0; i < surgeryNames.size(); ++i) {
        cout << left << setw(5) << i << setw(25) << surgeryNames[i]
        << fixed << setprecision(2) << surgeryCharges[i] << endl;
    }
}

//i am assuming i will have to change this to match PatientAccount
bool Surgery::addSurgeryCharge(PatientAccount &account, int id) {
    if (id < 0 || id >= NUM_SURGERIES) {
        return false; //invalid surgery ID
    }
    account.addCharge(surgeryCharges[id]);
    return true;
}
