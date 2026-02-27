#include <iostream>
#include <string>

using namespace std;

int main()
{
	int capital_letter = 0, small_letter = 0, number = 0; //대문자, 소문자, 숫자
	string s;
	cout << "암호를 입력하시오: ";
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (65 <= s[i] && s[i] <= 90) //대문자가 포함된 경우
		{
			capital_letter++;
		}
		else if (97 <= s[i] && s[i] <= 122)  //소문자가 포함된 경우
		{
			small_letter++;
		}
		else if (48 <= s[i] && s[i] <= 57) //숫자가 포함된 경우
		{
			number++;
		}
	}
	if (capital_letter > 0 && small_letter > 0 && number > 0) //3종류의 문자를 다 가지고 있는 경우 
	{
		cout << "안전합니다." << endl;
	}
	else
	{
		cout << "안전하지 않습니다." << endl;
	}
}