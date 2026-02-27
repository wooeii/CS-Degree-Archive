#include <iostream>
#include <string>
using namespace std;

int main()
{
	float list[]{ 0,10,20,30,40,50,60,70,80,90,100 };
	for (float i : list)
	{
		cout << i << "      " << (i - 32) * 5 / 9 << "\n";
	}
	return 0;
}