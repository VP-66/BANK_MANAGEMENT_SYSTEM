/*
#include <iostream>
#include <string>
#include "Accounts.h"
#include "Account.h"
#include "Savings.h"
#include "Fd.h"
#include "Loan.h"
#include "FixedLoan.h"
#include "VariableLoan.h"
#include "user.h"
using namespace std;

//function Implementations.
/////////////////////////////////////////////////

void newHomeLoan()
{
    int type;

    while (true)
    {
        cout << "\nWhich type of account would you like: "
             << "\n"
             << "\n1. Fixed rate \n"
             << "\n2. Variable rate \n";
        cout << "\nSelect an Option: ";
        if (cin >> type && (type == 1 || type == 2))
            break;
        cin.clear();
        cin.ignore(120, '\n');
        cout << "Error, please try again: " << endl;
    }

    if (type == 1)
    {
        Loan *NewLoan = new FixedLoan;
        NewLoan->create_account(type);
    }
    else if (type == 2)
    {
        Loan *NewLoan = new VariableLoan;
        NewLoan->create_account(type);
    }
}

void display_acc_details()
{

    Loan *ShowLoan = new FixedLoan;
    ShowLoan->show_account();
}

void modify_account()
{
    Loan *ModifyLoan = new FixedLoan;
    ModifyLoan->modify();
}

void deposit()
{
    Loan *LoanDeposit = new FixedLoan;
    LoanDeposit->dep();
}

void start_program_Loan(){
        int choice;

    while (1)
    {

        while (true)
        {
            cout << "\n\t\tlOAN MENU";
            cout << "\n====================================================";
            cout << "\n1. NEW LOAN ACCOUNT";
            cout << "\n2. SHOW EXISTING ACCOUNT";
            cout << "\n3. CHANGE LOAN TYPE TO VARIABLE";
            cout << "\n4. DEPOSIT ON EXISTING ACCOUNT";
            cout << "\n5. LOG OUT";
            cout << "\n====================================================";
            cout << "\nSelect an Option: ";
            if (cin >> choice && (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5))
                break;
            cin.clear();
            cin.ignore(120, '\n');
            cout << "Error, please try again: " << endl;
        }

        switch (choice)
        {
        case 1: //new account
            newHomeLoan();

            break;

        case 2: //show account

            display_acc_details();

            break;

        case 3:

            modify_account();

            break;

        case 4:

            deposit();

            break;

        case 5:

            cout << "Thankyou for using our system!" << endl;

            break;

        default:
            cout << "invalid option!" << endl;
            break;
        }
        if(choice == 5)
        {
            break;
        }
    }
}

void start_program_Account(){

    int Cash;

    cout << endl;

    cout << "How much cash do you currently have: ";
    while(true)
    {
        if(cin >> Cash && Cash >= 0)
        {
            break;
        }
        cout << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cout << "Please enter in a valid cash amount: ";
    }
    cout << endl;

    Accounts User(Cash);

    Savings Savings(500,"Savings","Car");
    Fd FixedDeposit(5000, "FixedDeposit",10);

    User.AddSavAccount(Savings);
    User.AddFdAccount(FixedDeposit);

    User.choice();

}

void start_program()
{
   std::cout << "___________________________________________________________"<< std::endl;
   cout<<endl;
   std::cout << "WELCOME TO OUR INTERNET BANKING SYSTEM!"<< std::endl;
   std::cout << "___________________________________________________________"<< std::endl;
   cout<<endl;

   string entereduser;
       std::cout<< "Please enter your username: ";
       getline(std::cin, entereduser);


   string enteredpassword;
       std::cout<< "Please enter your password (8-16 characters): ";
       cin >> enteredpassword;

       cout<<endl;


   User hello(entereduser,enteredpassword);
   std::cout << "Hello " << hello.getusername() << "!" <<std::endl;
   cout<<endl;

    while(true)
    {
        cout << "Enter 1 for Accounts or 2 for Loans or 3 to exit the program : ";
        int choice = 0;
        while(true)
        {
            if(cin >> choice && choice >= 1 && choice <= 3)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please choose a valid option: ";
        }
        cout << endl;

        switch(choice)
        {
            case 1:
                for(int i = 0;i < 50;i++)
                {
                    cout << endl;
                }
                start_program_Account();
                break;
            case 2:
                for(int i = 0;i < 50;i++)
                {
                    cout << endl;
                }
                start_program_Loan();
                cout << endl;
                break;
            case 3:
            cout << "Thankyou for using our program, we hope to see you soon" << endl;
            break;
        }
        if(choice == 3)
        {
            break;
        }
    }
}
*/