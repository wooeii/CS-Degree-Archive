#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size=0,integer=0,max=0,min=0;
	cout << "정수의 개수=";
	cin >> size;
	vector<int> vec(size); //벡터 생성
	for (auto& i : vec) //범위 기반 루프
	{
		cout << "정수를 입력하시오: ";
		cin >> integer;
		vec.push_back(integer); //벡터 추가 
		if (integer > max) 
		{
			max = integer;
		}
		if (integer < min) 
		{
			min = integer;
		}
		
	}
	cout << "최대값: " << max << endl;
	cout << "최소값: " << min << endl;
	return 0;
}