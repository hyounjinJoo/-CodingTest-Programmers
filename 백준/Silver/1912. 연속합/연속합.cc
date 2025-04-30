#include <iostream>
#include <limits>

#define NUMBERS_MAX_SIZE 100001
int main()
{
	long Origin[NUMBERS_MAX_SIZE], Sum[NUMBERS_MAX_SIZE], MaxValue = 0;
	int CountOfNumber = 0;

	std::cin >> CountOfNumber;

	for (int IDX = 0; IDX < CountOfNumber; ++IDX) std::cin >> Origin[IDX];

	MaxValue = Origin[0];
	Sum[0] = Origin[0];

	for(int IDX = 1; IDX < CountOfNumber; ++IDX)
	{
		Sum[IDX] = std::max(Sum[IDX - 1] + Origin[IDX], Origin[IDX]);
		MaxValue = std::max(Sum[IDX], MaxValue);
	}

	std::cout << MaxValue;

	return 0;
}