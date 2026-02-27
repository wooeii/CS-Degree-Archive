#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(const char* str);
	MyClass(const MyClass& other);
	~MyClass();
private:
	char* stored;
};

MyClass::MyClass(const char* str)//일반생성자
{
	stored = new char[strlen(str) + 1];
	strcpy(stored, str);
	cout << stored << endl;
	cout << "일반생성자" << endl;
}
MyClass::MyClass(const MyClass& other) //복사생성자
{
	this->stored = new char[strlen(other.stored) + 1];
	strcpy(this->stored, other.stored);
	cout << this->stored << endl;
	cout << "복사생성자" << endl;
}
MyClass::~MyClass()
{
	delete[] stored;
}

int main()
{
	MyClass a("ABCDEFG");
	MyClass b(a);
}