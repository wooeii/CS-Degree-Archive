#include <iostream>
using namespace std;

int main()
{
	string a;
	try
	{
		cout << "가위, 바위, 보 게임입니다." << endl;
		cout << "무엇을 내시겠습니까:";
		cin >> a;
		if (a == "가위" || a == "바위" || a == "보")
		{
			cout << "오류 없음" << endl;
		}
		else throw a;
	}
	catch (string e)
	{
		cout << "오류: \"가위\",\"바위\",\"보\" 중에서만 선택하세요.";
	}
	return 0;
}