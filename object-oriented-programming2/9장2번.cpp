#include <iostream>
using namespace std;

class Line {
public:
	int getLength(void) { return *ptr; }
	Line(int len);
	Line(const Line& other);
	~Line();
private:
	int* ptr;
};
//일반 생성자
Line::Line(int len)
{
	cout << "일반 생성자" << endl;
	ptr = new int;
	*ptr = len;
}
//복사 생성자
Line::Line(const Line& other)
{
	this->ptr = new int(*(other.ptr));
	cout << "복사 생성자" << endl;
}
Line::~Line()
{
	if (ptr != nullptr) delete this->ptr;
	ptr = nullptr;
}
int main()
{
	Line a(10);
	cout << "선의 길이: " << a.getLength() << endl;
	Line b(a);
	cout << "선의 길이: " << b.getLength() << endl;
	return 0;
}