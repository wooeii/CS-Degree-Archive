#include <iostream>

using namespace std;

class Airplane
{
	string name;
	int capacity, speed;
public:
	Airplane() //생성자
	{
		name = "";
		capacity = 0;
		speed = 0;
	}
	Airplane(string x, int y, int z) //생성자 중복정의
	{
		name = x;
		capacity = y;
		speed = z;
	}
	void setValue(string x, int y, int z);
	string getname();
	int getcapacity();
	int getspeed();
	void print();
};
void Airplane::setValue(string x, int y, int z) //설정자
{
	name = x;
	capacity = y;
	speed = z;
}
string Airplane::getname()//접근자
{
	return name;
}
int Airplane::getcapacity()//접근자
{
	return capacity;
}
int Airplane::getspeed()//접근자
{
	return speed;
}

void Airplane::print()
{
	cout << "비행기의 이름: " << name << endl;
	cout << "비행기의 용량: " << capacity << endl;
	cout << "비행기의 속도: " << speed <<"Km/h" << endl;
}

int main()
{
	Airplane a{ "보잉 787",900,300 };
	Airplane b;
	cout << "비행기 #1" << endl;
	a.print();
	cout << "비행기 #2" << endl;
	b.setValue("에어버스 350", 400, 1000);
	cout << "비행기의 이름: " << b.getname() << endl;
	cout << "비행기의 용량: " << b.getcapacity() << endl;
	cout << "비행기의 속도: " << b.getspeed() << "Km/h" << endl;
}
