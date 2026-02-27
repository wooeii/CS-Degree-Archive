#include <iostream>
using namespace std;

class Box {
private:
	double length, width, height;
public:
	Box(int l = 0, int w = 0, int h = 0) :length(l), width(w), height(h) {}
	bool operator<(Box& b2)
	{
		return (length < b2.length && width < b2.width && height < b2.height);
	}
	bool operator >(Box& b2)
	{
		return (length > b2.length && width > b2.width && height > b2.height);
	}
	void print()
	{
		cout << "상자의 길이: " << length << endl;
		cout << "상자의 너비: " << width << endl;
		cout << "상자의 높이: " << height << endl;
		cout << "상자의 부피: " << getVolume() << endl << endl;
	}
	double getVolume(void)
	{
		return length * width * height;
	}
};
int main()
{
	Box a(10, 10, 10), b(20, 20, 20);
	cout.setf(cout.boolalpha);
	cout << "상자#1" << endl;
	a.print();
	cout << "상자#2" << endl;
	b.print();
	cout << (a < b) << endl;
	cout << (a > b) << endl;
	return 0;
}