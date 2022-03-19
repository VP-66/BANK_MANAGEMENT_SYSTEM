
#ifndef LOAN_H
#define LOAN_H

#include <iostream> //used for input outputs
#include <string>   //used to include strings
using namespace std;

class Loan
{

protected:
    int AccNum;                   //holds account number
    string AccName;        //holds account name
    static int LoanBalance;     //holds balance of loan
    int initialDeposit;         // holds the deposit which customer has saved
    static float Currentinterest; //holds interest rate of loan
     static int LoanLife;          //holds the period of loan
    int salary;                   //holds salary for borrower
     static string type;           //holds the type of loan (fixed or variable)
    int quit;                     //holds decision from user to end program or not
    static float monthly_amount;  //monthly loan payments
     static float totalInterest;   //total interest customer has to pay on loan

public:
    //Default constructor
    Loan();

    //virtual function which will be used to check eligibility for each loan.
    virtual void Eligibility(float limit, int life, int salary, float initial) = 0;

    //virtual function to calculate monthly interest

    virtual float interestCal(float amount, float interest, int num_years) = 0;

    //creating a new loan account
    void create_account(int i);

    //show account details
    void show_account();

    //modify account details
    void modify();

    //add to loan
    void dep();

    //continue using program or not
    void continueprogram();

    //input validation
    void getInt(std::string prompt, std::string errorMessage, int min, int max, int*variable);

    //default constructor
    ~Loan()
    {
    }
};

#endif