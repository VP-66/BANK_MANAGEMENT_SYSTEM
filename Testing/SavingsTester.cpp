#include "Savings.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Savings s(4000,"Savings","House");

    if(s.getGoal() != "House")
    {
        cout << "Error" << endl;
    }

    s.ChangeGoal("Car");

    if(s.getGoal() != "Car")
    {
        cout << "Error" << endl;
    }

    return 0;
}
