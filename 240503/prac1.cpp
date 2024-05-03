//240503
//로또 추첨 프로그램

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int randomNumber[6] = {0};
	bool exit = true;
	std::srand(time(NULL));

	randomNumber[0] = std::rand() % 45 + 1;

	while (exit)
	{
		randomNumber[1] = std::rand() % 45 + 1;
		randomNumber[2] = std::rand() % 45 + 1;
		randomNumber[3] = std::rand() % 45 + 1;
		randomNumber[4] = std::rand() % 45 + 1;
		randomNumber[5] = std::rand() % 45 + 1;

		if (randomNumber[0] == randomNumber[1] == randomNumber[2] == randomNumber[3] == randomNumber[4] == randomNumber[5]) {
			exit = true;
		}
		else
			exit = false;

	}
	for (int i = 0; i < 6; i++)
	{
		std::cout << i + 1 << "번 : " << randomNumber[i] << "\n";
	}
	return 0;
}