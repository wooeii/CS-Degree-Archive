#include <iostream>

using namespace std;

class Employee
{
	string name;
	int age;
	int salary;
public:
	void information(string a, int b, int c);
	void print();
};

void Employee::information(string a, int b, int c)
{
	name = a;
	age = b;
	salary = c;
}
void Employee::print()
{
	cout << "Employee1:" << endl;
	cout << name << endl;
	cout << age << endl;
	cout << salary << endl;
}

int main()
{
	Employee a;
	a.information("±èÃ¶¼ö", 38, 2000000);
	a.print();
	return 0;
}
