#include <iostream>
using namespace std;

class Computer
{
	string name;
	int RAM;
	double cpu_speed;
public:
	void setComputer(string x, int  y , double z);
	void print();
};


void Computer::setComputer(string x, int y, double z)
{
	name = x;
	RAM = y;
	cpu_speed = z;
}

void Computer::print()
{
	cout << "이름: " << name << endl;
	cout << "RAM: " << RAM << endl;
	cout << "CPU 속도: " << cpu_speed << endl;
}

int main()
{
	Computer obj;
	obj.setComputer("오피스컴퓨터",8,4.2);
	obj.print();

	return 0;
}