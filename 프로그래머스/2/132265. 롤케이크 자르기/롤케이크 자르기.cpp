#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
	map<int, int> IronHas;
	map<int, int> LittleHas;

	size_t Length = topping.size();
	for (int Idx = 0; Idx < Length; ++Idx)
	{
		IronHas[topping[Idx]]++;
	}

	for (int Idx = 0; Idx < Length; ++Idx)
	{
		--IronHas[topping[Idx]];
		++LittleHas[topping[Idx]];

		if (0 == IronHas[topping[Idx]])
		{
			IronHas.erase(topping[Idx]);
		}

		if (IronHas.size() == LittleHas.size())
		{
			++answer;
		}
	}
    
    return answer;
}