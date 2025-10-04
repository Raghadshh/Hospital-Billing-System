//This is the implementation class for PatientAccount
#include "PatientAccount.h"



//constructor creates a new patient account with a daily rate, 0 days, 0 extra charges
PatientAccount::PatientAccount(double dr, int dy, double ex)
{  
    dailyRate = dr;
    extras = ex;
    days = dy;

}

PatientAccount::PatientAccount()
{
    days = 0;
    extras = 0.0;
    dailyRate = 850.50;
    
}

//sets the numbers of days the patient stayed in the hospital
void PatientAccount::setDays(int d)
{
    {
        if(d >= 0)
        {
            days = d;
        }
        else
            days = 0;
    }
}


//Adds all the additional charges
void PatientAccount::addCharge(double amount)
{
    if (amount > 0.0)
    {
        extras += amount;
    }
}



double PatientAccount::roomCharges() const
{
    return days * dailyRate;
}

//calculates the total charges
double PatientAccount::totalCharges() const
{
    return roomCharges() + extras;
}

//resets the account so the new patient info can be stored
void PatientAccount::reset()
{
    days = 0;
    extras = 0.0;
}

int PatientAccount::getDays() const {
    return days;
}

double PatientAccount::getExtras() const {
    return extras;
}