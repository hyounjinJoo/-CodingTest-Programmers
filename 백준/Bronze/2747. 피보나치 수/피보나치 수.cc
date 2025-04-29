#include <iostream>
#include <vector>

std::vector<int> Numbers(46);

int main()
{
	Numbers[0] = 0;
	Numbers[1] = 1;
	for(int IDX = 2; IDX < 46; ++IDX)
	{
		Numbers[IDX] = Numbers[IDX - 1] + Numbers[IDX - 2];
	}

	int InputN = 0;
	std::cin >> InputN;
	std::cout << Numbers[InputN];
}