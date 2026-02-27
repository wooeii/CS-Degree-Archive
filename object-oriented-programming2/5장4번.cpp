#include <iostream>
using namespace std;

class Movie
{
	string title;
	string director;
	float rating;

public:
	Movie() //생성자
	{
		title = "";
		director = "";
		rating = 0;
	}
	Movie(string x, string y, float z) :title{ x }, director{ y }, rating{ z } //멤버 초기화 리스트
	{

	}
	void setValue(string x, string y, float z);
	string gettitle();
	string getdirector();
	float getrating();
}; 
void Movie::setValue(string x, string y, float z) //설정자
{
	title = x;
	director = y;
	rating = z;
}
string Movie::gettitle() //접근자
{
	return title;
}
string Movie::getdirector() //접근자
{
	return director;
}
float Movie::getrating()//접근자
{
	return rating;
}

int main()
{
	Movie a{ "타이타닉","제임스 카메론",9.5 };
	Movie b;
	b.setValue("지오스톰","딘 데블린", 8.34);
	cout << "영화 #1" << endl;
	cout << "영화 제목: " << a.gettitle() << endl;
	cout << "영화 감독: " << a.getdirector() << endl;
	cout << "영화 평점: " << a.getrating() << endl;
	cout << "영화 #2" << endl;
	cout << "영화 제목: " << b.gettitle() << endl;
	cout << "영화 감독: " << b.getdirector() << endl;
	cout << "영화 평점: " << b.getrating() << endl;
}