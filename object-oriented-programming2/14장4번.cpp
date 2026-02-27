#include <iostream>
using namespace std;

template<class T>
T getSmallest(T arr[], int n)
{
	double min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
int main()
{
	double list[] = { 1.2,3.3,9.0,1.5,8.7 };
	cout <<"ÃÖ¼Ò°ª: " << getSmallest(list, 5) << endl;
	return 0;
}