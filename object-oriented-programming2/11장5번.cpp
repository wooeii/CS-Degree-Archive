#include <iostream>
#include <string>
using namespace std;

class Shape {
	int x, y;
	string color;
public:
	Shape(int a, int b, string c):x(a),y(b),color(c){}
	void setvalue(int a, int b, string c) { x = a; y = b; color = c; }
	int getx() { return x; }
	int gety() { return y; }
	double getArea() { return 0; }
};
class Circle :public Shape {
public:
	Circle(int x, int y, string z) :Shape(x, y, z) {}
	double getArea()
	{
		return  20*20 * 3.14;
	}
};
int main()
{
	Circle a(10,10,"원");
	cout <<"원의 면적: " << a.getArea() << endl;
	return 0;
}