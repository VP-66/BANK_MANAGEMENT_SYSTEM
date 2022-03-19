#ifndef SAVINGS_H
#define SAVINGS_H
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

class Savings : public Account
{
private:

public:

    string Goal;
    Savings();
    Savings(int Bal, string Type,string goal);
    void ChangeGoal(string newGoal);
    string getGoal();
    ~Savings();
};
#endif//