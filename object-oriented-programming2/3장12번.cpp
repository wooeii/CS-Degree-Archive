#include <iostream>
#include <string>

using namespace std;

int main()
{
	int counter[256] = { 0 }; //아스키코드
	string s;
	cout << "문자열을 입력하시오: ";
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		counter[s[i]]++; //문자를 아스키코드값 배열 위치에 저장
	}
	for (int j = 97; j <= 122; j++) //아스키코드 'a'=97,'z'=122
	{
		cout << char(j)<< ":" << counter[j] << endl;
	}
}