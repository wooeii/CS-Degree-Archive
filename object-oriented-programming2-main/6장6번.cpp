#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Contact
{
private:
	string name;
	string tel;
public:
	Contact(string a, string b) : name(a), tel(b) {}
	string get_name() { return name; }
	string get_tel() { return tel; }
};

int main()
{
	vector<Contact> list; 
	string a, b, search_name; 
	
	for (int i = 0; i < 3; i++)
	{
		cout << "이름을 입력하시오: "; 
		cin >> a; 
		cout << "전화번호를 입력하시오: "; 
		cin >> b; 
		list.push_back(Contact(a, b));
	}
	cout << "탐색하고 싶은 이름을 입력하시오:";
	cin >> search_name;
	for (int j = 0; j < 3; j++)
	{
		if (list[j].get_name() == search_name)
		{
			cout << "전화번호: " << list[j].get_tel() << endl;
		}
	}
	return 0;
}