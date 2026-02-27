#include <iostream>
using namespace std;

int main()
{
	int x = 0;
	try
	{
		cout << "나이를 입력하시오. :";
		cin >> x;
		if (x < 1) throw x;
		cout << "나이 : " << x << endl;
	}
	catch (int e)
	{
		cout << "오류: 양수를 입력하여야 함" << endl;
	}
	return 0;
}