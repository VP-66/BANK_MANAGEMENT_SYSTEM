#include "Loan.h"
#include "FixedLoan.h"
#include "VariableLoan.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    //test for variable loan
   Loan *test = new FixedLoan;

    float test1 = test->interestCal(100000,5.73,23);


    if(test1!=653){
        cout << "ERROR" << endl;
    }

    //test for variable loan

   Loan*test2 = new VariableLoan;

   float test_2 = test2->interestCal(100000,7.73,23);

    if(test_2!=776){
        cout << "ERROR" << endl;
    }

    return 0;
}


