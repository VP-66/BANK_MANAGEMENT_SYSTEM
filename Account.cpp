#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

    Account::Account()
    {
        Bal = 0;

        Type = "NULL";
    }

    Account::Account(int Balance, string AccType)
    {
        Bal = Balance;

        Type = AccType;

    }

    void Account::setBalance(int A)
    {
        Bal = A;
    }

    void Account::setAccType(string B)
    {
        Type = B;
    }

    int Account::getBalance()
    {
        return Bal;
    }
    string Account::getAccType()
    {
        return Type;
    }

    Account::~Account()
    {
    }