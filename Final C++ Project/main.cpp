#include "Patient.h"
#include "Surgery.h"
#include "Pharmacy.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {
  Patient p;

  // Creating a Pharmacy object
  Pharmacy m;

  Surgery s;
  
  p.setName();
  p.addDays(p);
  
  string medicationType;
  bool flag = true;
  int count = 0;
  while (flag) {
    char ans = 'y';
      cout << "Did your patient have any medications(Y or N)?" << endl;
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
      cout << "Medication Names Menu:\n"
        << "1. Antibiotic\n"
        << "2. Cough syrup\n"
        << "3. Vitamans\n"
        << "4. Antacid\n"
        << "5. Ibuprofen\n"
        << "Enter the medication type: ";
      cin >> medicationType;

      m.getCost(p,medicationType,count);
       
      count++;
    }
    else {
      flag = false;

    }
  }
  string surgeryType;
  bool banner = true;
  int surgeryCount = 0;

  while (banner) {
      char ans = 'y';
      cout << "Did your patient have any surgeries (Y or N)?" << endl;
      cin >> ans;
      if (ans == 'Y' || ans == 'y') {
          cout << "Surgery Menu:\n"
              << "1. Appendectomy\n"
              << "2. Knee Replacement\n"
              << "3. Cataract Surgery\n"
              << "4. Coronary artery bypass\n"
              << "5. Gallbladder Removal\n"
              << "Enter the surgery type: ";
          cin >> surgeryType;

          s.getCost(p,surgeryType,surgeryCount);
          surgeryCount++;
      } else {
         banner = false;
      }
  }
 s.returnSurgeryList(surgeryCount);
  m.returnPharmacyList(count);
  fstream outFile;
  
  outFile.open("Receipt.txt",ios::out);
  if(outFile.is_open()){
    outFile<<setw(20)<<"Receipt"<<endl;
    outFile<<"Patient:"<<setw(24)<<p.getName() << endl;
    outFile<<setw(20)<<"Charges"<<endl;
    outFile<<endl;
    for(int i = 0; i < count; i++){
      outFile << m.listOfMeds[i]<<endl;
    }

    for(int i = 0; i < surgeryCount; i++){
      outFile<<s.listOfSurgeries[i]<<endl;
    }
    outFile<<endl;
    outFile<<"Days:"<<setw(12)<<p.getDays()<<setw(11)<<"$"<<p.getDayCost()<<endl;

    outFile<<endl;
    outFile<<"Total:"<<setw(22)<<"$" <<p.getCharges()<<endl;
    
  }

  outFile.close();
  
  

  
  return 0;
}