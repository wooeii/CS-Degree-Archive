#include <iostream>
using namespace std;
template <typename T>
T getAvergage(T list[], int a)
{
	double sum = 0;
	for (int i = 0; i < a; i++)
	{
		sum += list[i];
	}
	return sum / a;
}
int main()
{
	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	double n = getAvergage(list, 5);
	cout << "Æò±Õ°ª: " << n << endl;
	return 0;
}