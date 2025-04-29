#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long long CountOfTrees = 0;
	std::cin >> CountOfTrees;

	// 2 3 4 3
	// 4 3 3 2
	// 5 5 6 6
	// + - - - =
	// | + - - =
	// | | + - - =
	// | | | + - =
	// | | | | | | |

	// 6
	// 39 39 38 35 20 9
	// 40 41 41 39 25 15
	// 42

	std::vector<long long> Times(CountOfTrees);
	for(long long IDX = 0; IDX < CountOfTrees; ++IDX)
	{
		std::cin >> Times[IDX];
	}

	std::sort(Times.begin(), Times.end(), std::greater<long long>());

	for(long long IDX = 0; IDX < CountOfTrees; ++IDX)
	{
		Times[IDX] += (IDX + 1);
	}

	std::sort(Times.begin(), Times.end(), std::greater<long long>());

	std::cout << Times[0] + 1;
}