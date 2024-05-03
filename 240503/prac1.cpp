//240503
//로또 추첨 프로그램

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int randomNumber[6] = {0};
	int sameNumber = 0;
	bool exit = true;
	std::srand(time(NULL));

	for (int i = 0; i < 6; i++)
	{
		randomNumber[i] = std::rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (randomNumber[j] == randomNumber[i])
				i--;
		}
	}



	for (int i = 0; i < 6; i++)
	{
		std::cout << i + 1 << "번 : " << randomNumber[i] << "\n";
	}
	return 0;
}