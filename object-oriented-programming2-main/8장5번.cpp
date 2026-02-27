#include <iostream>
#include <string>
using namespace std;

class Student {
	string name;
public:
	Student(string name = "") : name(name) {}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class MyClass {
	string className;
	Student* p;
	int size;
public:
	MyClass(string class_name = "", int size = 0) : className(class_name), size(size) 
	{ p = new Student[size]{ Student("홍길동"), Student("김철수"), Student("최자영") }; }
	void print();
	~MyClass() { delete[] p; }
};
void MyClass::print()
{
	cout << "학급 " << className << "의 학생들은 다음과 같다." << endl;
	for (int i = 0; i < size; i++) {
		cout << "학생 #" << i + 1 << ": " << p[i].getName() << endl;
	}
}

int main()
{
	MyClass special("special", 3);
	special.print();
	return 0;
}