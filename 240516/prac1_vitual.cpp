//240516
//prac1 �߻� Ŭ����

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
		cout << "���� �׸��ϴ�. \n";
	}
};

class Rect : public Shape
{
public:
	Rect() {}
	void draw() override
	{
		cout << "�簢���� �׸��ϴ�. \n";
	}
};

class Triangle : public Shape
{
public:
	Triangle() {}
	void draw() override
	{
		cout << "�ﰢ���� �׸��ϴ�. \n";
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