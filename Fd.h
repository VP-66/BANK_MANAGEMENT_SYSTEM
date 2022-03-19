#ifndef FD_H
#define FD_H
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

class Fd : public Account
{
private:

public:

    int term;
    Fd();
    Fd(int Bal,string Type,int termm);
    int getTerm();
    void setTerm(int Term);
    ~Fd();
};
#endif//