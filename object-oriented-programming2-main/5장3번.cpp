#include <iostream>

using namespace std;

class Box
{
	int length;
	int width;
	int height;
public:
	Box() //생성자
	{
		length = 0;
		width = 0;
		height = 0;
	}
	Box(int x, int y, int z) :length{ x }, width{ y }, height{ z } //멤버초기화리스트
	{
	}
	int empty();
	int getVolume();
	void setValue(int x, int y, int z);
	int getlength();
	int getwidth();
	int getheight();
	void print();

};
int Box::empty()
{
	if (length == 0 || width == 0 || height == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int Box::getVolume() 
{
	return length * width * height;
}
void Box::setValue(int x, int y, int z) //설정자
{
	length = x;
	width = y;
	height = z;
}
int Box::getlength()//접근자
{
	return length;
}
int Box::getwidth()//접근자
{
	return width;
}
int Box::getheight()//접근자
{
	return height;
}

void Box::print()
{
	cout << "상자의 길이: " << length << endl;
	cout << "상자의 너비: " << width << endl;
	cout << "상자의 높이: " << height << endl;
	cout << "상자의 부피: " << getVolume()<< endl;
}

int main()
{
	Box a, b;
	cout << "상자 #1" << endl;
	a.print();
	cout << "상자 #2" << endl;
	b.setValue(3, 2, 4);
	cout << "상자의 길이: " << b.getlength() << endl;
	cout << "상자의 너비: " << b.getwidth() << endl;
	cout << "상자의 높이: " << b.getheight() << endl;
	cout << "상자의 부피: " << b.getVolume() << endl;
}
