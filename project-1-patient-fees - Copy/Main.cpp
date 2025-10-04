//rate: 850.50 per day
#include<iostream>
#include "PatientAccount.h"
#include "Surgery.h" 
#include "Pharmacy.h"
#include<cctype>
#include<cstring>
using namespace std;

//safely get a positive integer
int getPositiveInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (!(cin >> value)) { 
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (value < 0) { 
            cout << "Please enter a non-negative number.\n";
        } else {
            return value; 
        }
    }
}

int main()
{
//delcare vars
char option;
bool running = true;
PatientAccount patient; 
Surgery surgery;
//Pharmacy pharmacy;


//Introduction to this
cout << "Welcome to Checkout!\n";
cout << "Enter in Options\n";
cout <<"D--For Days spent in care\nM--For Medication given\nS--For Surgery/Operation done\nE--To exit program and total bill\n";


//Set up loop
while(running){
    cout <<"\nEnter in Option:\n";
    cin >> option;
    option = toupper(static_cast<unsigned char>(option)); //it the user typed in 'd' this makes it 'D'

    //set up switch
    switch(option){
        case 'D':{
        int days = getPositiveInt("Enter number of days: ");
        patient.setDays(days);
        break;
        } 


        case 'S': {
            surgery.list(); 
            int id;
            cout << "Pick surgery (0–4): ";
            cin >> id;
            if (!surgery.addSurgeryCharge(patient, id))
            { 
                cout << "Invalid surgery id.\n"; 
            }
            
            break;
        }
        
        /*case 'M': { //waiting for the pharamcy class to be done
            pharm.list(); 
            int id; 
            cout << "Pick medication (0–4): ";
            cin >> id; 
            if (!pharm.addMedicationCharge(acct, id))
            { 
                cout << "Invalid medication id.\n"; 
            }
            
            break;
        }*/ 

        case 'E': {
            cout << "Exiting Options and totaling bill.\n";
            cout << "------------------------------------\n";
            cout << "Patient Bill\n";
            cout << "------------------------------------\n";
            cout << "Days in Hospital: " << patient.getDays() << endl;
            cout << "Room Charges: $" << patient.roomCharges() << endl;
            cout << "Surgery & Medication Charges: $" << patient.getExtras() << endl;
            cout << "------------------------------------\n";
            cout << "Total Bill: $" << patient.totalCharges() << endl;
            cout << "------------------------------------\n";
            patient.reset();
            running = false;
            break;
        }
        default:{
            cout << "\nERROR PLEASE TRY AGAIN!\n";
            break;
        }

    }//end of switch

}//end of while


    return 0;
}
