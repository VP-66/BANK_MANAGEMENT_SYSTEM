#ifndef VARIABLELOAN_H
#define VARIABLELOAN_H

#include <iostream> //used for input outputs
#include <string>   //used to include strings
using namespace std;
#include "Loan.h"


//INHERITENCE: VariableLoan class

class VariableLoan : public Loan
{

public:


    float interestCal(float amount, float interest, int num_years);

    virtual void Eligibility(float limit, int life, int salary, float initial);

};
#endif
