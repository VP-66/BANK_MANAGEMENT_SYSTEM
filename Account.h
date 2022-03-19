#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
public:

    Account();
    string Type;
    int Bal;
    Account(int Balance, string AccType);
    void setBalance(int A);
    void setAccType(string B);
    int getBalance();
    string getAccType();
    ~Account();
};
#endif//