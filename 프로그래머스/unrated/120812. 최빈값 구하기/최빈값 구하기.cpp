#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    size_t arraySize = array.size();

	int answer = -1;
	if (0 != arraySize)
	{
		std::vector<int> valueAppear;
		valueAppear.resize(1000);

		for (size_t index = 0; index < arraySize; ++index)
		{
			valueAppear[array[index]] += 1;
		}

		int minValuePos = 0;
		int foundedMinValue = 0;
		int countEqualValueAppear = 0;

		++arraySize;
		for (size_t index = 0; index < 1000; ++index)
		{
			if (foundedMinValue < valueAppear[index])
			{
				minValuePos = static_cast<int>(index);
				foundedMinValue = valueAppear[index];
				countEqualValueAppear = 0;
			}
			else if (foundedMinValue == valueAppear[index])
			{
				++countEqualValueAppear;
			}
		}

		if (0 == countEqualValueAppear)
		{
			answer = minValuePos;
		}
	}

	return answer;
}