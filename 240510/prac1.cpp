//240510
//클래스 사용해보기

#include <iostream>

using std::cout;
using std::cin;

class Rectangle {
public:
	Rectangle(int width, int height) : m_width(width), m_height(height){}
	float area()
	{
		return m_width * m_height;
	}
	//복사 생성자
	Rectangle(const Rectangle& Rect_copy)
	{
		// 멤버 변수 복사
		m_width = Rect_copy.m_width;
		m_height = Rect_copy.m_height;
	}

private:
	int m_width{ 0 };
	int m_height{ 0 };

};

int main() {
	int width, height;

	cout << "사각형의 가로와 세로 길이를 입력해주세요.";
	cin >> width >> height;

	Rectangle Rec1{ width, height };

	cout << "넓이 : " << Rec1.area() << "\n";

	Rectangle Rec_copy1(Rec1);
	//Rectangle Rec_copy2 = Rec1;


	//3
	Rectangle Rec2(30, 40);
	cout << "복사 전 넓이 : " << Rec2.area() << "\n";
	Rec2 = Rec_copy1;

	Rec2.area();

	cout << "복사 후 넓이 : " << Rec2.area() << "\n";


	return 0;
}