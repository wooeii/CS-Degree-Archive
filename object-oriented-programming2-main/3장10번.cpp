#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flip()
{
	return rand() % 2;
}
int main()
{
	srand(time(NULL));
	int front=0, back=0; //¾Õ¸é front, µÞ¸é back
	for (int i = 0; i < 100; i++)
	{
		if (flip() == 0) //¾Õ¸é
		{
			front++;
		}
		else //µÞ¸é
		{
			back++;
		}
	}
	cout << "µ¿ÀüÀÇ ¾Õ¸é: " << front << endl;
	cout << "µ¿ÀüÀÇ µÞ¸é: " << back << endl;
}