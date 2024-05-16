//240516
//prac1 추상 클래스

#include <iostream>

using namespace std;

class Shape {
public:
	Shape() {}
protected:
	virtual void draw() = 0;
};

class Circle : public Shape
{
public:
	Circle() {}
	void draw() override
	{
		cout << "원을 그립니다. \n";
	}
};

class Rect : public Shape
{
public:
	Rect() {}
	void draw() override
	{
		cout << "사각형을 그립니다. \n";
	}
};

class Triangle : public Shape
{
public:
	Triangle() {}
	void draw() override
	{
		cout << "삼각형을 그립니다. \n";
	}
};

int main()
{
	Circle cir;
	cir.draw();

	Rect rect;
	rect.draw();

	Triangle tri;
	tri.draw();

	return 0;
}