#include <iostream>

int main()
{
	long long Number = 0;
	std::cin >> Number;

	// 1부터 Number까지 반복
	// 각 반복에서 1~Number까지 반복하면서 나눠지는 숫자가 나오면 더한다.
	long long Answer = 0;
	long long StepNumber = 0;
	for(int CurrentNum = 1; CurrentNum <= Number; ++CurrentNum)
	{
		Answer += Number / CurrentNum * CurrentNum;
	}

	std::cout << Answer;
}