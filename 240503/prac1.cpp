//240503
//로또 추첨 프로그램

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int randomNumber[6] = {0};
	std::srand(time(NULL));

	// 난수 생성
	for (int i = 0; i < 6; i++)
	{
		randomNumber[i] = std::rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			// 중복 체크
			if (randomNumber[j] == randomNumber[i])
				i--;
		}
	}

	// 출력
	for (int i = 0; i < 6; i++)
	{
		std::cout << i + 1 << "번 : " << randomNumber[i] << "\n";
	}
	return 0;
}
