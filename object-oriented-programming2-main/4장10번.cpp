#include <iostream>

using namespace std;

class BankAccount
{
	string number;
	int balance;
public:
	void init(string, int);
	void deposit(int amount);
	void withdraw(int amount);
	int print();
};

void BankAccount::init(string x, int y)
{
	number = x;
	balance = y;
}
void BankAccount::deposit(int amount)
{
	balance = balance + amount;
}
void BankAccount::withdraw(int amount)
{
	balance = balance - amount;
}
int BankAccount::print()
{
	return balance;
}

int main()
{
	BankAccount a;
	int cash = 1000000;
	cout << "ÇöÀç ÀÜ¾×: " << cash << endl;
	a.init("94610200138698", cash);
	a.deposit(cash);
	cout << "after deposit(1000000) ÇöÀç ÀÜ¾×: " << a.print() << endl;
	a.withdraw(cash);
	cout << "after withdraw(1000000) ÇöÀç ÀÜ¾×: " << a.print() << endl;
	return 0;
}
