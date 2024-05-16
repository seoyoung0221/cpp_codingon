//240516
//prac1 ��� ����غ���
//prac2 �������̵� �����ϱ�

#include <iostream>

using namespace std;

class Shape {
public :
	Shape() {};
	Shape(float width, int lineNum)
	{
		this->m_width = width;
		this->m_lineNum = lineNum;
	}

	void printInfo()
	{
		cout << "���� ���� : " << m_lineNum << "\n";
		cout << "�غ��� ���� : " << m_width << "\n";
	}
protected:
	int m_lineNum;
	float m_width;
};

class Rectangle : public Shape
{
public :
	Rectangle(float width, float height)
		: Shape(width, 4)
	{
		this->m_width = width;
		this->m_height = height;
	};

	void area() 
	{
		cout << "���� : " << this->m_width * this->m_height << "\n";
	}

	void printInfo() 
	{
		cout << "�簢���� ���̴� " << this->m_width * this->m_height << "\n";
	}
	void printInfo(int w, int h)
	{
		cout << "�簢���� ���̴� " << w * h << "\n";
	}

private: 
	float m_width;
	float m_height;
};

class Triangle : public Shape
{
public : 
	/*
	Triangle(float width, float height)
		: Shape(width, 3), m_height(height), m_width(width){};
		*/

	Triangle(float width, float height) 
	{
		this->m_width = width;
		this->m_height = height;
		this->m_lineNum = 3;
	}

	void area()
	{
		cout << "���� : " << (this->m_width * this->m_height) / 2 << "\n";
	}

	void printInfo()
	{
		cout << "�ﰢ���� ���̴� " << this->m_width * this->m_height / 2<< "\n";
	}

	void printInfo(int w, int h)
	{
		cout << "�ﰢ���� ���̴� " << w * h /2 << "\n";
	}
private:
	//float m_width;
	float m_height;
};


int main() {

	float tri_width;
	float tri_height;
	cout << "�ﰢ���� �غ��� ���̸� �Է����ּ���. \n";
	cin >> tri_width >> tri_height;

	Triangle triangle(tri_width, tri_height);
	triangle.printInfo();
	triangle.printInfo(2, 5);
	//triangle.area();

	cout << "\n";

	float rect_width;
	float rect_height;

	cout << "�簢���� �غ��� ���̸� �Է����ּ���. \n";
	cin >> rect_width >> rect_height;

	Rectangle rectangle(rect_width, rect_height);
	rectangle.printInfo();
	//rectangle.area();


	return 0;
}