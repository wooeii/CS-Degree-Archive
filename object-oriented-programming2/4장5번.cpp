#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

class Dice 
{
	int face;
public:
	int roll();
};

int Dice::roll()
{
	return face = (int)(rand() % 6 + 1);
}

int main()
{
	srand(time(0));
	Dice a, b;
	cout << "주사위 값=" << a.roll() << endl;
	cout << "주사위 값=" << b.roll() << endl;
	return 0;
}
