#include <iostream>
using namespace std;

class HomeAppliance {
	int price;
public:
	virtual double getPrice() = 0;
	HomeAppliance(int a=0):price(a){}
};
class Television: public HomeAppliance {
	int price;
public:
	Television(int a=0) :price(a) {};
	double getPrice() { return (price * 0.9); }
};
class Refrigerator : public HomeAppliance {
	int price;
public:
	Refrigerator(int a = 0) :price(a) {};
	double getPrice() { return (price * 0.95); }
};
int main()
{
	HomeAppliance* a = new Television(100000);
	HomeAppliance* b = new Refrigerator(200000);
	HomeAppliance* c = new Television(300000);
	cout << "가격: " << a->getPrice() << endl;
	cout << "가격: " << b->getPrice() << endl;
	cout << "가격: " << c->getPrice() << endl;
	return 0;
}