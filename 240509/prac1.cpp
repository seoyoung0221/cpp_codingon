//prac 1
//����ü

#include <iostream>

using std::cout;
using std::cin;

struct Rectangle
{
	float width;
	float height;
};

int main() {
	Rectangle rec;

	cout << "����, ���θ� �Է��ϼ��� : ";
	cin >> rec.width >> rec.height;
	
	cout << "���̴� " << rec.width * rec.height << "�Դϴ�.";

	return 0;
}