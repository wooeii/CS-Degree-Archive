#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student
{
	string name;
	double marks;
public:
	Student(string n, double m): name{n},marks{m}{} 
	string get_name() { return name; }//접근자
	double get_marks() { return marks; }//접근자
	void print()
	{
		cout << "이름: " << name << endl;
		cout << "학점: " << marks << endl;
	}
};

bool compare(Student& p, Student& q) //비교함수
{
	return p.get_marks() > q.get_marks();
}

int main()
{
	vector<Student> list;
	list.push_back(Student("최자영",4.3));
	list.push_back(Student("김철수", 3.9));
	list.push_back(Student("김영희", 3.8));

	sort(list.begin(), list.end(), compare);
	cout << "=========================" << endl;
	for (auto& e : list)
	{
		e.print();
	}
	cout << "=========================" << endl;
	return 0;
}
