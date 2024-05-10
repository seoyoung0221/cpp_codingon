//240510
//클래스 사용해보기

#include <iostream>

using std::cout;
using std::cin;

class Rectangle {
public:
	Rectangle(int width, int height) : r_width(width), r_height(height){}
	int area()
	{
		return r_width * r_height;
	}

private:
	int r_width{ 0 };
	int r_height{ 0 };

};

int main() {
	int width, height;

	cout << "사각형의 가로와 세로 길이를 입력해주세요.";
	cin >> width >> height;

	Rectangle Rec1{ width, height };

	cout << "넓이 : " << Rec1.area() << "\n";

	return 0;
}