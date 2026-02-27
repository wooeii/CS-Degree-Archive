#include <iostream>

using namespace std;

class Complex
{
public:
	double r;
	double i;

	void add(double x, double y);
	void print();
};
void Complex::add(double x, double y)
{
	r = x;
	i = y;
}
void Complex::print()
{
	if (i > 0)
	{
		cout << r << " + " << i << "i" << endl;
	}
	else
	{
		i= i* (-1);
		cout << r << " - " << i << "i" << endl;
	}
}

int main()
{
	Complex a,b;
	a.add(5, 3);
	b.add(3, -4);
	a.print();
	b.print();
	return 0;
}
