//240510
//Ŭ���� ����غ���

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

	cout << "�簢���� ���ο� ���� ���̸� �Է����ּ���.";
	cin >> width >> height;

	Rectangle Rec1{ width, height };

	cout << "���� : " << Rec1.area() << "\n";

	Rectangle Rec_copy1(Rec1);
	//Rectangle Rec_copy2 = Rec1;


	//3
	Rectangle Rec2(30, 40);
	cout << "���� �� ���� : " << Rec2.area() << "\n";
	Rec2 = Rec_copy1;

	Rec2.area();

	cout << "���� �� ���� : " << Rec2.area() << "\n";


	return 0;
}