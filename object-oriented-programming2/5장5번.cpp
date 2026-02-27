#include <iostream>

using namespace std;

class Complex
{
	double r;
	double i;
public:
	Complex()
	{
		r = 0;
		i = 0;
	}
	Complex(double _r, double _i)
	{
		r = _r;
		i = _i;
	}
	void set_r(double _r) { r = _r; }
	void set_i(double _i) { i = _i; }
	double get_r() { return r; }
	double get_i() { return i; }
	void print();
};

Complex add(Complex a, Complex b)
{
	Complex sum;
	sum.set_r(a.get_r() + b.get_r());
	sum.set_i(a.get_i() + b.get_i());
	return sum;
}
void Complex::print()
{
	if (get_i() > 0)
	{
		cout << "(" << get_r() << "+" << get_i() << "i)";
	}
	else
	{
		cout << "(" << get_r() << "-" << -(get_i()) << "i)";
	}
}
int main()
{
	Complex a(5, 3);
	Complex b(3, -4);
	Complex sum = add(a,b);
	a.print();
	cout << "+";
	b.print();
	cout << "=";
	sum.print();
}