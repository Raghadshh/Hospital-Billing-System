#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

//This is the header file for PatientAccount

class PatientAccount{
    private:
        double dailyRate;
        int days;
        double extras;


    public:
        //constructor
        PatientAccount(double dr, int dy, double ex);
        PatientAccount();

        //setters
        void setDays(int d);
        void addCharge(double amount);

        //charges
        double roomCharges() const;
        double totalCharges() const;

        //reset the account being used but the dailyrate stays the same
        void reset();

        //getters
        int getDays() const;
        
        double getDailyRate() const;

        double getExtras() const;
    
};
#endif