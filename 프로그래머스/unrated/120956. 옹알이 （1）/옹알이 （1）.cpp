#include <string>
#include <vector>

using namespace std;

void SetChecker(vector<bool>& _checker, size_t _startIDX, size_t _endIDX)
{
	for (size_t index = _startIDX; index < _endIDX; ++index)
	{
		if (_checker[index] == true)
		{
			_checker[index] = false;
		}
		else
		{
			_checker[index] = true;
		}
	}
}

bool IsAllFalse(vector<bool>& _checker)
{
	size_t size = _checker.size();

	bool result = true;
	for (size_t index = 0; index < size; ++index)
	{
		if (_checker[index])
		{
			result = false;
			break;
		}
	}

	return result;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    int count = static_cast<int>(babbling.size());
    int saying = 0;  
    size_t pos = 0;
    
	vector<bool> checker;
    for(int index = 0; index < count; ++index)
    {
		checker.clear();
		checker.resize(babbling[index].size(), true);
        
        if((pos = babbling[index].find("aya")) != string::npos)
        {
			SetChecker(checker, pos, pos + 3);
        }
        if((pos = babbling[index].find("ye")) != string::npos)
        {
			SetChecker(checker, pos, pos + 2);
        }
        if((pos = babbling[index].find("woo")) != string::npos)
        {
			SetChecker(checker, pos, pos + 3);
        }
        if((pos = babbling[index].find("ma")) != string::npos)
        {
			SetChecker(checker, pos, pos + 2);
        }
        
		if (IsAllFalse(checker))
		{
			++answer;
		}
    }
    return answer;
}