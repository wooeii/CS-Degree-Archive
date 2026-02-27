#include <iostream>
#include <string>
using namespace std;

int main()
{
	int number, fibonacci1=0, fibonacci2=1, fibonaccitotal=0;
	cout << "몇 항까지 구할까요: ";
	cin >> number;

	for (int i = 0; i < number; i++)
	{
		if (i == 0)
		{
			cout << fibonacci1 << " ";
		}
		else if (i == 1)
		{
			cout << fibonacci2 << " ";
		}
		else
		{
			fibonaccitotal = fibonacci1 + fibonacci2;
			cout << fibonaccitotal << " ";
			fibonacci1 = fibonacci2;
			fibonacci2 = fibonaccitotal;
		}
	}
}