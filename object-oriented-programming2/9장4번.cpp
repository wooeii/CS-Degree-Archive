#include<iostream>
using namespace std;

class Point {
private:
	double xval, yval;
public:
	Point(double x = 0.0, double y=0.0):xval(x),yval(y){}
	double getX() { return xval; }
	double getY() { return yval; }
	void setxy(double x, double y) { xval = x; yval = y; }
};

void swap(Point& a, Point& b)
{
	Point c;
	c.setxy(a.getX(), a.getY());
	a.setxy(b.getX(), b.getY());
	b.setxy(c.getX(), c.getY());
}

int main()
{
	Point a(1.2, -2.8);
	Point b(3, 6);
	cout << "(" << a.getX() << "," << a.getY() << ")" << endl << "(" << b.getX() << "," << b.getY() << ")" << endl;
	swap(a, b);
	cout << "(" << a.getX() << "," << a.getY() << ")" << endl << "(" << b.getX() << "," << b.getY() << ")" << endl;
}