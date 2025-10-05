#ifndef SURGERY_H
#define SURGERY_H

#include <string>
#include <array>
#include "PatientAccount.h"
using namespace std;


class Surgery {
    private:
    static const int NUM_SURGERIES = 5;
    array<string, NUM_SURGERIES> surgeryNames;
    array<double, NUM_SURGERIES> surgeryCharges;
    
    public:
    Surgery(); // fixed price list
    
    void list() const;
    //i am assuming i will have to change this to match PatientAccount
    bool addSurgeryCharge(PatientAccount &account, int id);
};

#endif
