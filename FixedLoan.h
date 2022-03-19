#ifndef FIXEDLOAN_H
#define FIXEDLOAN_H

#include <iostream> //used for input outputs
#include <string>   //used to include strings
using namespace std;
#include "Loan.h"


//INHERITENCE: FixedLoan class

class FixedLoan : public Loan
{

public:

    float interestCal(float amount, float interest, int num_years);
    //function to calculate repayments

    //function to check if customer is eligible for the loan
    void Eligibility(float limit, int life, int salary, float initial);
};
#endif

