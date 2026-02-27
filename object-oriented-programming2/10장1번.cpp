#include <iostream>
using namespace std;

class Box {
private:
	double length, width, height;
public:
	Box(int l=0, int w=0, int h=0):length(l), width(w), height(h){}
	Box operator+(const Box& b2);
	void print()
	{
		cout << "상자의 길이: " << length << endl;
		cout << "상자의 너비: " << width << endl;
		cout << "상자의 높이: " << height << endl;
		cout << "상자의 부피: " << getVolume() << endl;
	}
	double getVolume(void)
	{
		return length * width * height;
	}
};
Box Box::operator+(const Box& b2)
{
	Box b;
	b.length = this->length + b2.length;
	b.width = this->width + b2.width;
	b.height = this->height + b2.height;
	return b;
}
int main()
{
	Box a(10, 10, 10), b(20, 20, 20), c;
	c = a + b;
	cout << "상자#1" << endl;
	a.print();
	cout << "상자#2" << endl;
	b.print();
	cout << "상자#3" << endl;
	c.print();
	return 0;
}