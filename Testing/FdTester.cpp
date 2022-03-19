#include "Fd.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Fd s(4000,"FixedDeposit",40);

    if(s.getTerm() != 40)
    {
        cout << "Error" << endl;
    }

    s.setTerm(10);

    if(s.getTerm() != 10)
    {
        cout << "Error" << endl;
    }

    return 0;
}

