//240510
//getter&setter 사용해보기

#include <iostream>

using std::cout;
using std::cin; 
using std::string;

class Rectangle {
public:
	Rectangle(int width, int height) : m_width(width), m_height(height) {}
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


	int getwidth() { return m_width; }
	int getheight() { return m_height; }

	void setwidth(int width) { this->m_width = width; }
	void setheight(int height) { this->m_height = height; }

private:
	int m_width{ 0 };
	int m_height{ 0 };

};


int main() {
	Rectangle rect(1, 2);
	cout << "넓이 : " << rect.area() << "\n";

	int width, height;
	cout << "사각형의 가로 세로 길이를 입력하세요. \n";
	cin >> width >> height;

	rect.setwidth(width);
	rect.setheight(height);

	cout << "넓이 : " << rect.area() <<"\n가로 길이 : " << rect.getwidth() << "\n세로 길이 : " << rect.getheight();

	return 0;
}