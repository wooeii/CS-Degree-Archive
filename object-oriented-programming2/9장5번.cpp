#include <iostream>
using namespace std;
class Box {
private:
	double length;
	double width;
	double height;
public:
	static int count; //정적변수
	Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		length = l;
		width = w;
		height = h;
		count++;
	}
	double Volume() {
		return length * width * height;
	}
	static int getCount() //정적함수 
	{
		return count;
	}
};
int Box::count = 0; //정적변수 초기화 
int main()
{
	Box a, b;
	cout <<"전체 객체 수: " << Box::count << endl;
	return 0;
}