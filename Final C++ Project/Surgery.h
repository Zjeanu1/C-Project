#include <iostream>
#include "Patient.h"
#include <fstream>
#include <iomanip>
using namespace std;


class Surgery {
public:
    static const int MAX = 10;

    string listOfSurgeries[MAX];
    float getSurgeryCost(Patient &p,const string& surgeryType, int c);

    void returnSurgeryList(int c) {
        for (int i = 0; i < c; i++) {
            cout <<left << listOfSurgeries[i] << setw(22)<<fixed<<right;
            if (listOfSurgeries[i] == "Appendectomy") {
               listOfSurgeries[i].append("               $2500");
            } else if (listOfSurgeries[i] == "Knee Replacement") {
                listOfSurgeries[i].append("           $5000");
            } else if (listOfSurgeries[i] == "Cataract Surgery") {
              listOfSurgeries[i].append("           $1500");
            } else if (listOfSurgeries[i] == "Coronary artery bypass") {
              listOfSurgeries[i].append("     $3500");
            } else if (listOfSurgeries[i] == "Gallbladder Removal") {
                listOfSurgeries[i].append("        $3000");
            
            // Add more surgery types and costs as needed
        }
    }
      
    }


    void getCost(Patient &p,const string& surgeryType, int c);
};

void Surgery::getCost(Patient &p,const string& surgeryType, int c) {
    if (surgeryType == "1") {
        listOfSurgeries[c] = "Appendectomy";
        addCharge(p,2500);
        c++;
        
        
    } else if (surgeryType == "2") {
        listOfSurgeries[c] = "Knee Replacement";
        addCharge(p,5000);
      c++;
        
    } else if (surgeryType == "3") {
        listOfSurgeries[c] = "Cataract Surgery";
        addCharge(p,1500);
        c++;
        
    } else if (surgeryType == "4") {
        listOfSurgeries[c] = "Coronary artery bypass";
        addCharge(p,3500);
        c++;
      
    } else if (surgeryType == "5") {
        listOfSurgeries[c] = "Gallbladder Removal";
        addCharge(p,3000);
        c++;
      
    
        
    }
    else{
    cout<<"Surgery not found!"<<endl;
      
    }
   
}

