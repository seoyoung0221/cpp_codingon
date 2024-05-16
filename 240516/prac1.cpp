//240516
//prac1 상속 사용해보기
//prac2 오버라이딩 이해하기

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
		cout << "변의 개수 : " << m_lineNum << "\n";
		cout << "밑변의 길이 : " << m_width << "\n";
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
		cout << "넓이 : " << this->m_width * this->m_height << "\n";
	}

	void printInfo() 
	{
		cout << "사각형의 넓이는 " << this->m_width * this->m_height << "\n";
	}
	void printInfo(int w, int h)
	{
		cout << "사각형의 넓이는 " << w * h << "\n";
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
		cout << "넓이 : " << (this->m_width * this->m_height) / 2 << "\n";
	}

	void printInfo()
	{
		cout << "삼각형의 넓이는 " << this->m_width * this->m_height / 2<< "\n";
	}

	void printInfo(int w, int h)
	{
		cout << "삼각형의 넓이는 " << w * h /2 << "\n";
	}
private:
	//float m_width;
	float m_height;
};


int main() {

	float tri_width;
	float tri_height;
	cout << "삼각형의 밑변과 높이를 입력해주세요. \n";
	cin >> tri_width >> tri_height;

	Triangle triangle(tri_width, tri_height);
	triangle.printInfo();
	triangle.printInfo(2, 5);
	//triangle.area();

	cout << "\n";

	float rect_width;
	float rect_height;

	cout << "사각형의 밑변과 높이를 입력해주세요. \n";
	cin >> rect_width >> rect_height;

	Rectangle rectangle(rect_width, rect_height);
	rectangle.printInfo();
	//rectangle.area();


	return 0;
}