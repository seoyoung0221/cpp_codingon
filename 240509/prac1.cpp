//prac 1
//구조체

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

	cout << "가로, 세로를 입력하세요 : ";
	cin >> rec.width >> rec.height;
	
	cout << "넓이는 " << rec.width * rec.height << "입니다.";

	return 0;
}