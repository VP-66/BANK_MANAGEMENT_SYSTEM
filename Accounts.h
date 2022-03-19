#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"
#include "Accounts.h"
#include "Savings.h"
#include "Fd.h"
using namespace std;

class Accounts
{
private:

    int AmntAccounts;
    int T;
    int CurrentCash;
    int index;
    int savindex;
    int fixindex;
    int Deposit;
    string DepositAcc;
    int Withdraw;
    string WithdrawAcc;
    int TotalSavingsDeposit;
    int TotalFDDeposit;
    int TotalSavingsWithdraw;
    int TotalFDWithdraw;
    int Transferamnt;
    string fromAcc;
    string toAcc;
    int indexfrom;
    int indexto;
    string Goal;
    int Term;


public:

    Account *accounts;
    Savings *sav;
    Fd *fixed;
    Accounts(int csh);
    void setCash(int Cs);
    int getCash();
    void AddSavAccount(Savings AA);
    void AddFdAccount(Fd BB);
    Account* getAccounts();
    void deposit(Account *array);
    void depositCash(int cashamnt, Account XW);
    bool EnoughDepositCash(int number);
    void withdraw(Account *array);
    void WithdrawCash(int ccashamnt, Account XW);
    bool EnoughWithdrawCash(int number, Account XW);
    void transferselect(Account *array);
    void transferMoney(Account From, Account To,int howmuch);
    bool Enoughtransfer(Account fromm, int howmuchh);
    void DisplayAccounts(Account *array);
    void EditAccDetails(Account *array);
    void choice();
    ~Accounts();

};

#endif//