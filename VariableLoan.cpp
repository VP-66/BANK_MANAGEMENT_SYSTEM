
#include <iostream> //used for input outputs
#include <string>   //used to include strings
using namespace std;
#include "VariableLoan.h"
#include <cmath>


float VariableLoan::interestCal(float amount, float interest, int num_years)
    {

        float months, intrest_used, primary, temp, deno, num, constant, x;
        int y, i, n;
        float totalrepayment;
        i = 1;
        constant = 1;
        primary = amount;
        intrest_used = interest;
        y = num_years;
        x = intrest_used / 1200;
        n = (y * 12);
        temp = 1 + (x);
        while (i <= n)
        {
            constant = constant * temp;
            i++;
        }
        num = constant * primary * (x);
        deno = constant - 1;
        months = num / deno;
        monthly_amount = months;
        totalrepayment = monthly_amount * num_years * 12;
        totalInterest = totalrepayment - amount;
        cout << "\nAt an interest rate of " << interest << "% the details of the repayments are: " << endl;
        cout << "\nTotal Loan repayment is: $" << round(totalrepayment) << endl;
        cout << "\nTotal amount of interest paid is: $" << round(totalInterest) << endl;
        cout << "\nYour principal and interest repayments would be $" << round(monthly_amount) << " per month" << endl;

        return round(monthly_amount);
    }

        void VariableLoan::Eligibility(float limit, int life, int salary, float initial)
    {

        if (limit <= 1000000 && life <= 30 && salary >= 35000 && initial >= (0.3 * limit))
        {
            if (system("CLS")) system("clear");
            cout << "\nGREAT! YOU ARE CONDITIONALLY APPROVED FOR THIS VARIABLE LOAN!" << endl;
            Currentinterest = 7.73;
            interestCal(limit, 7.73, life);
            continueprogram();
        }
        else
        {
            if (system("CLS")) system("clear");
            cout << "\nSORRY! YOUR LOAN APPLICATION WAS UNSUCCESSFUL. PLEASE TRY AGAIN LATER!" << endl;
            AccNum = 51728;
            Currentinterest = 2.73;
            type = "fixed";
            LoanBalance = 560000;
            LoanLife = 15;
            AccName = "UserName";
            continueprogram();
        }
    }