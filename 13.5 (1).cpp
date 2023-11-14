#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class SavingsAccount
{
public:
    void openAccount(int, int);
    void makeDeposit(int, int);
    void makeWithdrawal(int, int);
    void showCurrentBalance();
    SavingsAccount();
    SavingsAccount(int, int);

private:
    int dollars;
    int cents;

    void normalizeCents() {
        while(cents >= 100){
            dollars += cents / 100;
            cents %= 100;
        }

        if(cents < 0){
            dollars -= 1;
            cents = 100 + cents;
        }
    }

};

int main()
{ 
  SavingsAccount theAccount;

int initialDollars, initialCents;
cout << "Please input the initial dollars: ";
cin >> initialDollars;
cout << "Please input the initial cents: ";
cin >> initialCents;

theAccount.openAccount(initialDollars, initialCents);

char makeDepositChoice;
cout << "Would you like to make a deposit? Y or y for yes: ";
cin >> makeDepositChoice;

while (makeDepositChoice == 'Y' || makeDepositChoice == 'y')
{
int depositDollars, depositCents;
cout << "Please input the dollars to be deposited: ";
cin >> depositDollars;
cout << "Please input the cents to be deposited: ";
cin >> depositCents;

theAccount.makeDeposit(depositDollars, depositCents);
cout << "Would you like to make another deposit? Y or y for yes: ";
cin >> makeDepositChoice;
}

char makeWithdrawalChoice;
cout << "Would you like to make a withdrawal? Y or y for yes: ";
cin >> makeWithdrawalChoice;

while (makeWithdrawalChoice == 'Y' || makeWithdrawalChoice == 'y')
{
int withdrawalDollars, withdrawalCents;
cout << "Please input the dollars to be withdrawn: ";
cin >> withdrawalDollars;
cout << "Please input the cents to be withdrawn: ";
cin >> withdrawalCents;

theAccount.makeWithdrawal(withdrawalDollars, withdrawalCents);

cout << "Would you like to make another withdrawal? Y or y for yes: ";
cin >> makeWithdrawalChoice;
}
      theAccount.showCurrentBalance();
      return 0;
  }

SavingsAccount::SavingsAccount()
{
    dollars = 0;
    cents = 0;
}

SavingsAccount::SavingsAccount(int d, int c)
{
    dollars = d;
    cents = c;
}



void SavingsAccount::openAccount(int initialDollars, int initialCents)
{
    dollars = initialDollars;
    cents = initialCents;
    normalizeCents();
}

void SavingsAccount::makeDeposit(int depositDollars, int depositCents)
{
    dollars += depositDollars;
    cents += depositCents;
    normalizeCents();
}

void SavingsAccount::makeWithdrawal(int withdrawalDollars, int withdrawalCents)
{
    dollars -= withdrawalDollars;
    cents -= withdrawalCents;
    normalizeCents();
}

void SavingsAccount::showCurrentBalance()
{
    cout << "Dollars = " << dollars << "      Cents = " << cents << endl;
}