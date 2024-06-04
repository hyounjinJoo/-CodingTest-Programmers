#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> Elements)
{
	int Answer = 0;

	set<int> ResultValues;

	int ElementSize = Elements.size();
	int ResultSum = 0;
	for (int OutIdx = 0; OutIdx < ElementSize; ++OutIdx)
	{
		for (int InnerIdx = OutIdx; InnerIdx < OutIdx + ElementSize; ++InnerIdx)
		{
			int Slot = InnerIdx % ElementSize;
			ResultSum += Elements[Slot];
			ResultValues.emplace(ResultSum);
		}
		ResultSum = 0;
	}

	return ResultValues.size();
}