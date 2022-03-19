#include "Account.h"
#include "Savings.h"
#include "Fd.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Savings s(4000,"Savings","Lol");

    if(s.getBalance() != 4000)
    {
        cout << "Error" << endl;
    }

    s.setBalance(10);

    if(s.getBalance() != 10)
    {
        cout << "Error" << endl; 

    if(s.getAccType() != "Savings")
    {
        cout << "Error" << endl;
    }

    s.setAccType("FixedDeposit");

    if(s.getAccType() != "FixedDeposit")
    {
        cout << "Error" << endl;
    }

    return 0;
}
