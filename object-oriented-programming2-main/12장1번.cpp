#include <iostream>
using namespace std;

class Shape {
	int x, y;
public:
	virtual double getArea() = 0;
	Shape(int a=0, int b=0):x(a),y(b){}
};
class Rect:public Shape{
	int a, b;
public:
	Rect(int a=0, int b=0):a(a),b(b) {}
	double getArea() { return a * b; }
};
class Circle:public Shape{
	int a, b;
public:
	Circle(int a = 0, int b = 0) :a(a), b(b) {}
	double getArea() { return a * b * 3.14; }
};
class Triangle:public Shape{
	int a, b;
public:
	Triangle (int a = 0, int b = 0) :a(a), b(b) {}
	double getArea() { return (a * b) / 2; }
};
int main()
{
	Shape* shapes[3];
	shapes[0] = new Rect(4, 5);
	shapes[1] = new Circle(4, 4);
	shapes[2] = new Triangle(4, 5);
	for (int i=0; i<3; i++)
	{
		cout << "도형 #" << i << "의 면적: " << shapes[i]->getArea() << endl;
	}
	return 0;

}