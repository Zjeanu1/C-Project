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
  
  char ans;
  char ans2;
  string medicationType;
  int count = 0;
  cout << "Did the patient take any medication (Y or N)?" << endl;

  cin >> ans;

  if (ans == 'Y' || ans == 'y') {

      cout << "Medication Names Menu:\n"
          << "1. Antibiotic\n"
          << "2. Cough syrup\n"
          << "3. Vitamins\n"
          << "4. Antacid\n"
          << "5. Ibuprofen\n"
          << "Enter the medication type: ";
      cin >> medicationType;

      m.getCost(p, medicationType, count);

      count++;

      bool flag = true;
      while (flag) {
          cout << "Did the patient take any more medication (Y or N)?" << endl;
          cin >> ans2;
          if (ans2 == 'Y' || ans2 == 'y') {

              cout << "Medication Names Menu:\n"
                  << "1. Antibiotic\n"
                  << "2. Cough syrup\n"
                  << "3. Vitamins\n"
                  << "4. Antacid\n"
                  << "5. Ibuprofen\n"
                  << "Enter the medication type: ";
              cin >> medicationType;
              m.getCost(p, medicationType, count);

              count++;
          }
          else {
              flag = false;
          }
      }


  }
  string surgeryType;
  bool banner = true;
  int surgeryCount = 0;
  ans = 'y';


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

      s.getCost(p, surgeryType, surgeryCount);
      surgeryCount++;

      while (banner) {
          ans = 'y';
          cout << "Did your patient have any more surgeries (Y or N)?" << endl;
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

              s.getCost(p, surgeryType, surgeryCount);
              surgeryCount++;
          }
          else {
              banner = false;
          }
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