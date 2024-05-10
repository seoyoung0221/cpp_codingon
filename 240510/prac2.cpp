//240510
//getter&setter ����غ���

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
	//���� ������
	Rectangle(const Rectangle& Rect_copy)
	{
		// ��� ���� ����
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
	cout << "���� : " << rect.area() << "\n";

	int width, height;
	cout << "�簢���� ���� ���� ���̸� �Է��ϼ���. \n";
	cin >> width >> height;

	rect.setwidth(width);
	rect.setheight(height);

	cout << "���� : " << rect.area() <<"\n���� ���� : " << rect.getwidth() << "\n���� ���� : " << rect.getheight();

	return 0;
}