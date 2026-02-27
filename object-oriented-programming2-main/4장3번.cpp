#include <iostream>
using namespace std;

class Sum
{
	int n1;
	int n2;
public:
	void init(int x, int y);
	int add();
};


void Sum::init(int x, int y)
{
	n1 = x;
	n2 = y;

}

int Sum::add()
{
	return n1 + n2;
}

int main()
{
	Sum a;
	int x, y;
	cout << "첫 번째 정수: ";
	cin >> x;
	cout << "두 번째 정수: ";
	cin >> y;
	a.init(x, y);
	cout << "연산 결과:" << a.add() << endl;
	return 0;
}