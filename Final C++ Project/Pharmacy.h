#include <iostream>
#include "Patient.h"
#include <fstream>
#include <iomanip>
using namespace std;

class Pharmacy {
public:
   static const int MAX = 10;

    string listOfMeds[MAX];
    float getMedicationCost(Patient &p,const string& medicationType,int c);
    
    
    void returnPharmacyList(int c) {
        for (int i = 0; i < c;i++) {
            cout <<left << listOfMeds[i];
            if(listOfMeds[i] == "Antibiotic"){
              listOfMeds[i].append("                 $50");
              
            }
            else if(listOfMeds[i] == "Cough Syrup"){
              listOfMeds[i].append("                $80");
            }
            else if(listOfMeds[i] == "Vitamins"){
              listOfMeds[i].append("                   $30");
            }
            
            else if(listOfMeds[i] == "Antacid"){
              listOfMeds[i].append("                    $25");
            }
            else if(listOfMeds[i] == "Ibuprofen"){
              listOfMeds[i].append("                  $40");
            }
        }
      
    }
    void getCost(Patient &p,const string& medicationType,int c);
    
    
};



void Pharmacy::getCost(Patient &p,const string& medicationType,int c) {
    
    if (medicationType == "1") {
        listOfMeds[c] = "Antibiotic";
        addCharge(p,50);
        c++;
        

    }   
    else if (medicationType == "2") {
        listOfMeds[c] = "Cough Syrup";
        c++;
        addCharge(p,80);
        
    }
    else if (medicationType == "3") {
        listOfMeds[c] = "Vitamins";
        c++;
        addCharge(p,30);
        
    }
    else if (medicationType == "4") {
        listOfMeds[c] = "Antacid";
        c++;
        addCharge(p,25);
       
    }
    else if (medicationType == "5") {
        listOfMeds[c] = "Ibuprofen";
        c++;
        addCharge(p,40);
      
    }
    else{
      cout << "Medication not found!" << endl;
    }
   


}