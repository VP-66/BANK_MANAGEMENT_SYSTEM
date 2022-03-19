#include "Accounts.h"
#include "Savings.h"
#include "Fd.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    //Set an initial cash amount
    int Cash = 1000;

    // Creating 2 Account objects - one in the form of a Savings object and another in the form of a FixedDeposit object
    Savings S(2000,"Savings","House");
    Fd F(5000,"FixedDeposit",30);

    //Create an Accounts object
    Accounts All(Cash);

    //Test setter and getter of Cash function
    int test = 200;
    All.setCash(test);
    if(All.getCash() == test)
    {
        cout << "Cash function succesful" << endl;
    }

    //Test Add accounts function
    All.AddSavAccount(S);
    All.AddFdAccount(F);
    for(int i = 0; i < 2; i++)
    {
        cout << (All.getAccounts())[i].getAccType() << endl;
    }

    //Test Deposit function
    if(All.EnoughDepositCash(40) == 1)
    {
        All.depositCash(40,S);
        cout << "Successful" << endl;
    }

    //Test Withdrawal function
    if(All.EnoughWithdrawCash(4000,F) == 1)
    {
        All.WithdrawCash(4000,F);
        cout << "Successful" << endl;
    }

    //Test Transfer funcion
    if(All.Enoughtransfer(F,200) == 1)
    {
        All.transferMoney(F,S,200);
        cout << "Successful" << endl;
    }

    //Test Display function
    All.DisplayAccounts(All.getAccounts());

    return 0;
}
