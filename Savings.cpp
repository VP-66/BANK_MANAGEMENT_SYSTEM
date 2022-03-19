#include "Savings.h"
#include <iostream>
#include <string>

using namespace std;

    Savings::Savings()
    {
        Goal = "NULL";
    }

    Savings::Savings(int Bal, string Type,string goal) : Account(Bal,Type)
    {
        Goal = goal;
    }

    void Savings::ChangeGoal(string newGoal)
    {
        Goal = newGoal;
    }

    string Savings::getGoal()
    {
        return Goal;
    }

    Savings::~Savings()
    {

    }