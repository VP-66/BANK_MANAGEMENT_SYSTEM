output: main.o Accounts.o Account.o Savings.o Fd.o Loan.o VariableLoan.o FixedLoan.o user.o
	g++ main.o Accounts.o Account.o Savings.o Fd.o Loan.o VariableLoan.o FixedLoan.o user.o -o output

main.o: main.cpp
	g++ -c main.cpp

Accounts.o: Accounts.h Accounts.cpp
	g++ -c Accounts.cpp

Account.o: Account.h Account.cpp
	g++ -c Account.cpp

Savings.o: Savings.h Savings.cpp
	g++ -c Savings.cpp

Fd.o: Fd.h Fd.cpp
	g++ -c Fd.cpp

Loan.o: Loan.h Loan.cpp
	g++ -c Loan.cpp

VariableLoan.o: VariableLoan.h VariableLoan.cpp
	g++ -c VariableLoan.cpp

FixedLoan.o: FixedLoan.h FixedLoan.cpp
	g++ -c FixedLoan.cpp

user.o: user.h user.cpp
	g++ -c user.cpp

clean:
	rm *.o output