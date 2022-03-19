#include "Fd.h"
#include <iostream>
#include <string>

using namespace std;

    Fd::Fd()
    {
        term = 0;
    }

    Fd::Fd(int Bal,string Type,int termm) : Account(Bal,Type)
    {
        term = termm;
    }

    int Fd::getTerm()
    {
        return term;
    }


    void Fd::setTerm(int Term)
    {
        term = Term;
    }


    Fd::~Fd()
    {
    }
