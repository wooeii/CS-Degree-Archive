#include <iostream>
using namespace std;

class Person
{
	string name;
	int age;
public:
	void setPerson(string x, int  y); 
	void print();
};


void Person::setPerson(string x, int y)
{
	name = x;
	age = y;
}

void Person::print()
{
	cout << "ÀÌ¸§: " << name << endl;
	cout << "³ªÀÌ: " << age << endl;
}

int main()
{
	Person a;
	a.setPerson("±èÃ¶¼ö", 21);
	a.print();
}