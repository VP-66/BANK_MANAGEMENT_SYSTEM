#include "Accounts.h"
#include <iostream>
#include <string>
using namespace std;


    Accounts::Accounts(int csh)
    {
        AmntAccounts = 0;

        accounts = new Account[5];
        index = 0;

        sav = new Savings[5];
        savindex = 0;

        fixed = new Fd[5];
        fixindex = 0;

        CurrentCash = csh;

        Deposit = 0;
        DepositAcc = "NULL";
        TotalSavingsDeposit = 0;
        TotalFDDeposit = 0;

        Withdraw = 0;
        WithdrawAcc = "NULL";
        TotalSavingsWithdraw = 0;
        TotalFDWithdraw = 0;

        Transferamnt = 0;
        fromAcc = "NULL";
        toAcc = "NULL";
        indexfrom = 0;
        indexto = 0;

        Goal = "NULL";
        Term = 0;

        T = 0;
    }

    void Accounts::setCash(int Cs)
    {
        CurrentCash = Cs;
    }

    int Accounts::getCash()
    {
        return CurrentCash;
    }

    void Accounts::AddSavAccount(Savings AA)
    {
        accounts[index] = AA;
        sav[savindex] = AA;
        AmntAccounts++;
        index++;
        savindex++;
        TotalSavingsDeposit = sav[0].getBalance();
    }

    void Accounts::AddFdAccount(Fd BB)
    {
        accounts[index] = BB;
        fixed[fixindex] = BB;
        AmntAccounts++;
        index++;
        fixindex++;
        TotalFDDeposit = fixed[0].getBalance();
    }

    bool Accounts::EnoughDepositCash(int number)
    {
        if((getCash() - number) >= 0)
        {
            return true;
        }
        cout << "Not enough cash available" << endl;
        return false;
    }

    void Accounts::deposit(Account *array)
    {
        cout << "Current cash: " << getCash() << endl;
        cout << "How much cash do you want to deposit?: ";
        while(true)
        {
            if(cin >> Deposit && Deposit >= 0)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please enter a valid deposit amount: ";
        }
        cout << endl;

        while(EnoughDepositCash(Deposit) != 1)
        {
            cout << "Please try again" << endl;
            cout << "Current cash: " << getCash() << endl;
            cout << "How much cash do you want to deposit?: ";
            while(true)
            {
                if(cin >> Deposit && Deposit >= 0)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please enter a valid deposit amount: ";
            }
            cout << endl;
        }

        for(int i = 0; i < AmntAccounts; i++)
        {
            cout << (i+1) << ". " << array[i].getAccType();
            if(array[i].getAccType() == "Savings")
            {
                T = TotalSavingsDeposit - TotalSavingsWithdraw;
                array[i].setBalance(T);
            }
            else if(array[i].getAccType() == "FixedDeposit")
            {
                T = TotalFDDeposit - TotalFDWithdraw;
                array[i].setBalance(T);
            }
            cout << ", Current Balance: " << array[i].getBalance() << endl;
        }

        cout << "Which account do you want to deposit cash into?: ";

        int choice = 0;

        while(true)
        {
            if(cin >> choice && choice >= 1 && choice <= 2)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please try again, enter either 1 or 2: ";
        }
        cout << endl;

        if (array[choice-1].getAccType() == "Savings")
        {
            TotalSavingsDeposit = TotalSavingsDeposit + Deposit;
            depositCash(Deposit,array[choice-1]);
        }
        else if(array[choice-1].getAccType() == "FixedDeposit")
        {
            TotalFDDeposit = TotalFDDeposit + Deposit;
            depositCash(Deposit,array[choice-1]);
        }

    }

    void Accounts::depositCash(int cashamnt, Account XO)
    {
        if(XO.getAccType() == "Savings")
        {
            T = TotalSavingsDeposit - TotalSavingsWithdraw;
        }
        else if(XO.getAccType() == "FixedDeposit")
        {
            T = TotalFDDeposit - TotalFDWithdraw;
        }

        XO.setBalance(T);

        cout << "Cash deposited in " << XO.getAccType() << " successfully." << endl;

        cout << "Current balance of " << XO.getAccType() << " account is: " << XO.getBalance() << endl;

        setCash(getCash() - cashamnt);

        cout << "Current cash: " << getCash() << endl;
    }

    void Accounts::withdraw(Account *array)
    {
        for(int i = 0; i < AmntAccounts; i++)
        {
            cout << (i+1) << ". " << array[i].getAccType();
            if(array[i].getAccType() == "Savings")
            {
                T = TotalSavingsDeposit - TotalSavingsWithdraw;
                array[i].setBalance(T);
            }
            else if(array[i].getAccType() == "FixedDeposit")
            {
                T = TotalFDDeposit - TotalFDWithdraw;
                array[i].setBalance(T);
            }
            cout << ", Current Balance: " << array[i].getBalance() << endl;
        }

        cout << "Which account do you wish to withdraw cash from?: ";
        int choice = 0;
        while(true)
        {
            if(cin >> choice && choice >= 1 && choice <= 2)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please try again, enter either 1 or 2:" << endl;
        }
        cout << endl;

        cout << "Current cash: " << getCash() << endl;
        cout << "How much cash do you want to withdraw: ";
        while(true)
        {
            if(cin >> Withdraw && Withdraw >= 0)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please enter a valid withdrawal amount: ";
        }
        cout << endl;

        while(EnoughWithdrawCash(Withdraw,array[choice-1]) != 1)
        {
            cout << "Please try again" << endl;
            for(int i = 0; i < AmntAccounts; i++)
            {
                cout << (i+1) << ". " << array[i].getAccType();
                if(array[i].getAccType() == "Savings")
                {
                    T = TotalSavingsDeposit - TotalSavingsWithdraw;
                    array[i].setBalance(T);
                }
                else if(array[i].getAccType() == "FixedDeposit")
                {
                    T = TotalFDDeposit - TotalFDWithdraw;
                    array[i].setBalance(T);
                }
                cout << ", Current Balance: " << array[i].getBalance() << endl;
            }
            cout << "Which account do you wish to withdraw cash from?: ";
            int choice = 0;
            while(true)
            {
                if(cin >> choice && choice >= 1 && choice <= 2)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please try again, enter either 1 or 2: ";
            }
            cout << endl;

            cout << "Current cash: " << getCash() << endl;
            cout << "How much cash do you want to withdraw: ";
            while(true)
            {
                if(cin >> Withdraw && Withdraw >= 0)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please try again, enter either 1 or 2: ";
            }
            cout << endl;
        }

        if(array[choice-1].getAccType() == "Savings")
        {
            TotalSavingsWithdraw = TotalSavingsWithdraw + Withdraw;
            WithdrawCash(Withdraw,array[choice-1]);
        }
        else if(array[choice-1].getAccType() == "FixedDeposit")
        {
            TotalFDWithdraw = TotalFDWithdraw + Withdraw;
            WithdrawCash(Withdraw,array[choice-1]);
        }
    }

    void Accounts::WithdrawCash(int ccashamnt, Account XW)
    {
        if(XW.getAccType() == "Savings")
        {
            T = TotalSavingsDeposit - TotalSavingsWithdraw;
        }
        else if(XW.getAccType() == "FixedDeposit")
        {
            T = TotalFDDeposit - TotalFDWithdraw;
        }

        XW.setBalance(T);

        cout << "Cash successfully withdrawn from " << XW.getAccType() << " account." << endl;

        cout << "Current balance of " << XW.getAccType() << " account is: " << XW.getBalance() << endl;

        setCash(getCash() + ccashamnt);

        cout << "Current cash: " << getCash() << endl;
    }

    bool Accounts::EnoughWithdrawCash(int number, Account XW)
    {
        if((T - number) >= 0)
        {
            return true;
        }
        cout << "Not enough funds to available in account" << endl;
        return false;
    }

    Account* Accounts::getAccounts()
    {
        return accounts;
    }

    void Accounts::transferselect(Account *array)
    {
        for(int i = 0; i < AmntAccounts; i++)
        {
            cout << array[i].getAccType();
            if(array[i].getAccType() == "Savings")
            {
                T = TotalSavingsDeposit - TotalSavingsWithdraw;
                array[i].setBalance(T);
            }
            else if(array[i].getAccType() == "FixedDeposit")
            {
                T = TotalFDDeposit - TotalFDWithdraw;
                array[i].setBalance(T);
            }
            cout << ", Current Balance: " << array[i].getBalance() << endl;
        }
        cout << "How much money did you want to transfer between accounts: ";
        while(true)
        {
            if(cin >> Transferamnt && Transferamnt >= 0)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please enter a valid transfer amount: ";
        }
        cout << endl;

        for(int i = 0; i < AmntAccounts; i++)
        {
            cout << (i+1) << ". " << array[i].getAccType();
            if(array[i].getAccType() == "Savings")
            {
                T = TotalSavingsDeposit - TotalSavingsWithdraw;
                array[i].setBalance(T);
            }
            else if(array[i].getAccType() == "FixedDeposit")
            {
                T = TotalFDDeposit - TotalFDWithdraw;
                array[i].setBalance(T);
            }
            cout << ", Current Balance: " << array[i].getBalance() << endl;
        }

        cout << "Which account did you want to transfer the money out of?: ";
        int from = 0;
        while(true)
        {
            if(cin >> from && from >= 1 && from <= 2)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please try again , enter 1 or 2: ";
        }
        cout << endl;

        cout << "Which account did you want to transfer the money into?: ";
        int to = 0;
        while(true)
        {
            if(cin >> to && to >= 1 && to <= 2 && to != from)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please try again, enter 1 or 2";
        }
        cout << endl;

        while(Enoughtransfer(array[from-1],Transferamnt) != 1)
        {
            cout << "Please try again" << endl << endl;
            for(int i = 0; i < AmntAccounts; i++)
            {
                cout << array[i].getAccType();
                if(array[i].getAccType() == "Savings")
                {
                    T = TotalSavingsDeposit - TotalSavingsWithdraw;
                    array[i].setBalance(T);
                }
                else if(array[i].getAccType() == "FixedDeposit")
                {
                    T = TotalFDDeposit - TotalFDWithdraw;
                    array[i].setBalance(T);
                }
                cout << ", Current Balance: " << array[i].getBalance() << endl;
            }
            cout << "How much money did you want to transfer between accounts: ";
            while(true)
            {
                if(cin >> Transferamnt && Transferamnt >= 0)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please enter a valid transfer amount: ";
            }
            cout << endl;

            for(int i = 0; i < AmntAccounts; i++)
            {
                cout << (i+1) << ". " << array[i].getAccType();
                if(array[i].getAccType() == "Savings")
                {
                    T = TotalSavingsDeposit - TotalSavingsWithdraw;
                    array[i].setBalance(T);
                }
                else if(array[i].getAccType() == "FixedDeposit")
                {
                    T = TotalFDDeposit - TotalFDWithdraw;
                    array[i].setBalance(T);
                }
                cout << ", Current Balance: " << array[i].getBalance() << endl;
            }

            cout << "Which account did you want to transfer the money out of?: ";
            int from = 0;
            while(true)
            {
                if(cin >> from && from >= 1 && from <= 2)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please try again , enter 1 or 2: ";
            }
            cout << endl;

            cout << "Which account did you want to transfer the money into?: ";
            int to = 0;
            while(true)
            {
                if(cin >> to && to >= 1 && to <= 2 && to != from)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please try again, enter 1 or 2";
            }
            cout << endl;
         }
        transferMoney(array[from-1],array[to-1],Transferamnt);
    }

    void Accounts::transferMoney(Account From, Account To,int howmuch)
    {
        if(From.getAccType() == "Savings")
        {
            TotalSavingsWithdraw = TotalSavingsWithdraw + howmuch;
            T = TotalSavingsDeposit - TotalSavingsWithdraw;
            From.setBalance(T);
        }
        else if(From.getAccType() == "FixedDeposit")
        {
            TotalFDWithdraw = TotalFDWithdraw + howmuch;
            T = TotalFDDeposit - TotalFDWithdraw;
            From.setBalance(T);
        }

        if(To.getAccType() == "Savings")
        {
            TotalSavingsDeposit = TotalSavingsDeposit + howmuch;
            T = TotalSavingsDeposit - TotalSavingsWithdraw;
            To.setBalance(T);
        }
        else if(To.getAccType() == "FixedDeposit")
        {
            TotalFDDeposit = TotalFDDeposit + howmuch;
            T = TotalFDDeposit - TotalFDWithdraw;
            To.setBalance(T);
        }

        cout << "Transfer successfull, your " << From.getAccType() <<" account now has " <<
        From.getBalance() << " dollars and your " << To.getAccType() << " account now has " <<
        To.getBalance() << " dollars in it." << endl;

    }

    bool Accounts::Enoughtransfer(Account fromm, int howmuchh)
    {
        if(fromm.getAccType() == "Savings")
        {
            T = TotalSavingsDeposit - TotalSavingsWithdraw;
        }
        else if(fromm.getAccType() == "FixedDeposit")
        {
            T = TotalFDDeposit - TotalFDWithdraw;
        }

        if((T - howmuchh) >= 0)
        {
            return true;
        }
        cout << "Not enough funds in account to transfer" << endl;
        return false;
    }


    void Accounts::DisplayAccounts(Account *array)
    {
        cout << "Here are your account details:" << endl;
        cout << endl;
        for(int i = 0; i < AmntAccounts; i++)
        {
            cout << array[i].getAccType() << " Account: " << endl;
            cout << "Current Balance: ";
            if(array[i].getAccType() == "Savings")
            {
                int D1 = TotalSavingsDeposit;
                int W1 = TotalSavingsWithdraw;
                T = TotalSavingsDeposit - TotalSavingsWithdraw;
                array[i].setBalance(T);
                cout << array[i].getBalance() << endl;
                cout << "Total money inflow: " << D1 << endl;
                cout << "Total money outflow: " << W1 << endl;
            }
            else if(array[i].getAccType() == "FixedDeposit")
            {
                int D2 = TotalFDDeposit;
                int W2 = TotalFDWithdraw;
                T = TotalFDDeposit - TotalFDWithdraw;
                array[i].setBalance(T);
                cout << array[i].getBalance() << endl;
                cout << "Total money inflow: " << D2 << endl;
                cout << "Total money outflow: " << W2 << endl;
            }
            cout << endl;
        }
        cout << "Current Cash: " << getCash() << endl;
        cout << endl;
    }

    void Accounts::EditAccDetails(Account *array)
    {
        for(int i = 0; i < AmntAccounts; i++)
        {
            cout << (i+1) << ". " << array[i].getAccType() << endl;
        }
        cout << "Which account would you like to access: ";
        int choice = 0;
        while(true)
        {
            if(cin >> choice && choice >= 1 && choice <= 2)
            {
                break;
            }
            cout << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cout << "Please try again, enter 1 or 2: ";
        }
        cout << endl;

        if (array[choice-1].getAccType() == "Savings")
        {
            cout << "Current goal: " << sav[0].getGoal() << endl;
            cout << endl;
            cout << "Would you like to change your goal? If so, enter Y, if not enter N" << endl;
            string change = "NULL";
            cin >> change;
            cout << endl;
            while(change != "Y" && change != "N")
            {
                cout << "Please try again, enter Y or N: ";
                cin >> change;
                cout << endl;
            }

            if(change == "Y")
            {
                cout << "Please enter in your new goal: ";
                cin >> Goal;
                cout << endl;
                sav[0].ChangeGoal(Goal);
                cout << "Your new goal has successfully been set to: " << sav[0].getGoal() << endl;
            }
            else if (change == "N")
            {
                cout << endl;
            }
        }
        else if(array[choice-1].getAccType() == "FixedDeposit")
        {
            cout << "Current Term: " << fixed[0].getTerm() << " years" << endl;
            cout << "Would you like to extend your current term? If so, enter Y, if not enter N: ";
            string change = "NULL";
            cin >> change;
            cout << endl;
            while(change != "Y" && change != "N")
            {
                cout << "Please try again, enter Y or N: ";
                cin >> change;
                cout << endl;
            }

            if(change == "Y")
            {
                cout << "Please enter in by how many years you would like to extend your current term: ";
                int extend = 0;
                while(true)
                {
                    if(cin >> extend && extend >= 0)
                    {
                        break;
                    }
                    cout << endl;
                    cin.clear();
                    cin.ignore(120,'\n');
                    cout << "Please enter a valid extension period: ";
                }
                cout << endl;
                Term = fixed[0].getTerm();
                Term = Term + extend;
                fixed[0].setTerm(Term);
                cout << "Your new term has successfully been extended to: " << fixed[0].getTerm() << " years" << endl;
            }
            else if (change == "N")
            {
                cout << endl;
            }
        }
    }



    void Accounts::choice()
    {
        int n = 1;
        string lol;
        while(n == 1)
        {
            if (system("CLS")) system("clear");
            int choice = 0;

            cout << "                          WELCOME TO ACCOUNTS                        " << endl;
            cout << " Select from the following actions below what service you were after " << endl;
            cout << "---------------------------------------------------------------------" << endl;
            cout << "1. Review Account Summaries" << endl;
            cout << "2. Edit Account Details" << endl;
            cout << "3. Deposit Cash" << endl;
            cout << "4. Withdraw Cash" << endl;
            cout << "5. Transfer money between accounts" << endl;
            cout << "6. End Session" << endl;

            cout << "Which service would you like to use: ";
            while(true)
            {
                if(cin >> choice && choice >= 1 && choice <= 6)
                {
                    break;
                }
                cout << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cout << "Please choose an option between 1 to 6 inclusive: ";
            }
            cout << endl;
            switch(choice)
            {
                case 1:
                    DisplayAccounts(getAccounts());
                    cout << "Enter any key to return to the menu screen: ";
                    cin >> lol;
                    cout << endl;
                    break;
                case 2:
                    EditAccDetails(getAccounts());
                    cout << "Enter any key to return to the menu screen: ";
                    cin >> lol;
                    cout << endl;
                    break;
                case 3:
                    deposit(getAccounts());
                    cout << "Enter any key to return to the menu screen: ";
                    cin >> lol;
                    cout << endl;
                    break;
                case 4:
                    withdraw(getAccounts());
                    cout << "Enter any key to return to the menu screen: ";
                    cin >> lol;
                    cout << endl;
                    break;
                case 5:
                    transferselect(getAccounts());
                    cout << "Enter any key to return to the menu screen: ";
                    cin >> lol;
                    cout << endl;
                    break;
                case 6:
                    n = 0;
                    break;
            }
            if(n != 1)
            {
                break;
            }
        }
    }

    Accounts::~Accounts()
    {
        delete[] (accounts);
        delete[] (sav);
        delete[] (fixed);
        TotalSavingsDeposit = 0;
        TotalFDDeposit = 0;

        TotalSavingsWithdraw = 0;
        TotalFDWithdraw = 0;
    }
