#include <iostream>
using namespace std;

int main()
{
	int* p;
	int input=0;
	cout << "몇 개의 정수를 입력합니까? ";
	cin >> input;
	p = new int[input]; //동적 배열
	for (int i = 0; i < input; i++)
	{
		cout << "정수를 입력하시오 : ";
		cin >> p[i];
	}
	cout << "입력된 정수는: ";
	for (int j = 0; j < input; j++)
	{
		cout << p[j] << ", ";
	}
	delete [] p; //동적 해제
	return 0;
}