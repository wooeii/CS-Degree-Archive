#include <iostream>

using namespace std;

class Triangle
{
	int b, h, a;
public:
	void information(int x, int y);
	void area();
};

void Triangle::information(int x, int y)
{
	b = x;
	h = y;
}
void Triangle::area()
{
	a = (b * h) / 2;
	cout << "밑변이 " << b << "이고 높이가 " << h << "인 삼각형의 면적: " << a << endl;
}

int main()
{
	Triangle a;
	a.information(3,4);
	a.area();
	return 0;
}
