#include <iostream>
using namespace std;

class Box {
	friend void printBox(Box box);
private:
	double length, width, height;
public:
	Box(int l = 0, int w = 0, int h = 0) :length(l), width(w), height(h) {}
	double getVolume(void)
	{
		return length * width * height;
	}
};
void printBox(Box box)
{
	cout << "상자의 길이: " << box.length << endl;
	cout << "상자의 너비: " << box.width << endl;
	cout << "상자의 높이: " << box.height << endl;
	cout << "상자의 부피: " << box.getVolume() << endl;
}
int main()
{
	Box a(10, 10, 10);
	cout << "상자#1" << endl;
	printBox(a);
	return 0;
}