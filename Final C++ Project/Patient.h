#pragma once

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Patient {

friend class Surgery;


private:
	float charges;
	int days;
	const float dayRate = 1250;
	string fname;
	string lname;

public:

	//Constructor
	Patient() {
		charges = 0;
		days = 0;
		fname = "";
		lname = "";

		}


	//Setters
	void setName() {


		cout << "Enter your patient's first name:" << endl;
		cin >> fname;
		cout << "Enter your patient's last name:" << endl;
		cin >> lname;

	}

	friend void addCharge(Patient &p, float c);
	
	int addDays(Patient &p) {
    bool flag = true;

    while(flag){
      int d;
      cout << "How many days did your patient spend in the hospital?"<<endl;
      cin>>d;
      if (d > 0) {
		    days += d;
        flag = false;
        addCharge(p,days*dayRate);
      }
      else{
        cout<<"Not a valid number of days, please try again"<<endl;
        
      }

	}
    return days;
  }


	//Getters

	float getCharges() {
		return charges;

	}

	string getName() {
	 return lname+", "+fname;

	}

  int getDays(){
   return days;
    
  }

  int getDayCost(){
    return days*dayRate;
  }


    friend class Pharmacy;
    friend class Surgery;
};

void addCharge(Patient &p, float c){
  p.charges+=c;
  
}