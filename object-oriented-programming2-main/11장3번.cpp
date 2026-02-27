#include <iostream>
#include <string>
using namespace std;

class Employee {
	string name;
	int salary;
public:
	Employee(string x="", int y = 0) :name(x), salary(y) {}
	int computeSalary() { return salary; }
	void setsalary(int x) { salary = x; }
	string getname() { return name; }
};
class Manager :public Employee {
	int bonus;
public:
	Manager(string x, int y, int z=0): Employee(x,y), bonus(z) {}
	int getbonus() { return bonus; }
	void setbonus(int x) { bonus = x; }
	int computeSalary()
	{
		return Employee::computeSalary() + bonus;
	}
};
int main()
{
	Manager a("김철수", 200, 100);
	cout << "이름: " << a.getname() << endl;
	cout << "월급: " << a.Employee::computeSalary() << endl;
	cout << "보너스: " << a.getbonus() << endl;
	cout << "전체 급여: " << a.computeSalary() << endl;
	return 0;
}