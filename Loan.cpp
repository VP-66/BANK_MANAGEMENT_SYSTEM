#include <iostream> //used for input outputs
#include <string>   //used to include strings
using namespace std;
#include "Loan.h"
#include <climits>
#include <cmath>

//method implementation from Loan class

int Loan::LoanBalance = 560000;
int Loan::LoanLife = 15;
string Loan::type = "fixed";
float Loan::monthly_amount = 4645;
float Loan::totalInterest = 275975;
float Loan::Currentinterest = 5.73;


//1. Constructor
Loan::Loan()
{ //default constructor
    AccNum = 51728;
}

//2. Continue program

void Loan::continueprogram() //this function checks if the users wishes to exit or continue the program
{
    while (true)
    {
        cout << "\n====================================================";
        cout << "\nDo you wish to:" << endl;
        cout << "\n1. Continue using the software" << endl;
        cout << "\n2. Exit the software" << endl;
        cout << "\nSelect an Option: ";
        if (cin >> quit && (quit == 1 || quit == 2))
            break;
        cin.clear();
        cin.ignore(120, '\n');
        cout << "Error, please try again: " << endl;
    }

    if (quit == 1)
    {
        if (system("CLS")) system("clear");
    }
    else
    {
        if (system("CLS")) system("clear");
        cout << "Thankyou for using our system!" << endl;
        exit(0);
    }
    cout << "\n";
}

// input validation

void Loan::getInt(std::string prompt, std::string errorMessage, int min, int max, int*variable) {
    while (true)
    {
    int*ptr = variable;
        cout << prompt;
        if (cin >> *(ptr) && *(ptr) >= min && *(ptr) <= max)
            break;
        cin.clear();
        cin.ignore(120, '\n');
        cout << errorMessage << endl;
    }
}


//3. create account

void Loan::create_account(int i)
{
    int type = i;
    string choice;
    int loantype;
    cout << "\n\nNEW HOME LOAN ACCOUNT FORM\n";
    cout << "====================================================";
    cout << "\n";


    cout << "Enter Account Name: ";
    std::getline(std::cin >> std::ws, AccName);


    getInt("Enter borrowing limit (from $100k upto $1million): ", "Sorry, this limit is invalid. Try again and sure you only enter numbers: ", 100000, 1000000, &LoanBalance);

    getInt("Enter life of Loan (up to 30 years): ", "Sorry, this life of loan is invalid. Try again: ", 0,30, &LoanLife);

    getInt("Enter current annual salary (Nearest whole number): ", "Sorry, your entered salary is invalid. Try again: ", 0,INT_MAX, &salary);


    if (type == 1 && salary < 30000) //customer must have 30k income for fixed rate
    {
        if (system("CLS")) system("clear");
        cout << "\nYour salary seems a bit low for the fixed loans offered by us!" << endl;
        continueprogram();
    }

    if (type == 2 && salary < 35000) //customer must have 35k income for fixed rate
    {
        if (system("CLS")) system("clear");
        cout << "\nYour salary seems a bit low for the variable loans offered by us!" << endl;
        continueprogram();
    }

    getInt("Enter initial deposit saved (Nearest whole number): ", "Sorry, your entered deposit is invalid. Try again: ", 0, INT_MAX, &initialDeposit);

    if (type == 1 && (initialDeposit < (0.2 * LoanBalance))) //customer must have 20% of borrow limit of fixed
    {
        if (system("CLS")) system("clear");
        cout << "Your deposit seems a bit low for the fixed loans offered by us!" << endl;
        continueprogram();
    }

    if (type == 2 && (initialDeposit < (0.3 * LoanBalance))) //customer must have 30% of borrow limit of variable
    {
        if (system("CLS")) system("clear");
        cout << "Your deposit seems a bit low for the variable loans offered by us!" << endl;
        continueprogram();
    }

    //check eligibility of the applicant:
    Eligibility(LoanBalance, LoanLife, salary, initialDeposit);
}

//4. show account details

void Loan::show_account()
{
    if (system("CLS")) system("clear");
    cout << "Account Number: " << AccNum << endl;
    cout << "Account Type: " << type << endl;
    cout << "Account balance: -$" << LoanBalance << endl;
        if (LoanBalance == 0)
    {
    Currentinterest = 0;
    LoanLife = 0;
    totalInterest = 0;
    monthly_amount = 0;
    }
    cout << "Curent interest rate: " << Currentinterest << "%" << endl;
    cout << "Loan life: " << LoanLife << " years " << endl;
    cout << "Total amount of interest paid is: " << round(totalInterest) << endl;
    cout << "Your principal and interest repayments would be $" << round(monthly_amount) << " per month" << endl;
    cout << "\n\n";
    continueprogram();
}

//5. modify account details

void Loan::modify()
{
    if (system("CLS")) system("clear");
    int choice;


    while (true)
    {
        cout << "\nWhich type of account would you like: "
             << "\n\n"
             << "1. Fixed rate \n\n"
             << "2. Variable rate \n\n";
        cout << "Select an Option: ";
        if (cin >> choice)
            break;
        cin.clear();
        cin.ignore(120, '\n');
        cout << "Error, please try again: " << endl;
    }

    if (choice != 1)
    {
        if (system("CLS")) system("clear");
        type = "variable";
        cout << "Your account has been changed to VARIABLE! " << endl;
    }

    if (type == "fixed")
    {
        if (system("CLS")) system("clear");
        cout << "\nThis is already the current type!" << endl;
    }
    else
    {
        type = "variable";
        Currentinterest = 7.73;
    }

    cout << "\nYour new details are: ";
    show_account();
}

//6. Add deposit to the loan

void Loan::dep()
{
    float deposit;
    while (true)
    {
        if (system("CLS")) system("clear");
        cout << "There is $" << LoanBalance << " remaining on the loan, how much will you like to deposit: ";
        if (cin >> deposit && deposit <= LoanBalance)
            break;
        cin.clear();
        cin.ignore(120, '\n');
        cout << "Error, please try again: " << endl;
    }

    LoanBalance = LoanBalance - deposit;
    if (LoanBalance == 0)
    {
        if (system("CLS")) system("clear");
        cout << "\nCONGRATS! YOU HAVE PAID OFF YOUR LOAN!" << endl;
        cout << "\n";
        continueprogram();
    }

    else

    {
        if (system("CLS")) system("clear");
        cout << "Success! There is $" << LoanBalance << " remaining on the loan!" << endl;
        cout << "\n";
        continueprogram();
    }
}