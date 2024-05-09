#include <string>
#include <vector>

using namespace std;
int RemoveZeroCount = 0;
int CallChange = 0;

void RemoveZero(string& Str)
{
    while (string::npos != Str.find('0'))
	{
		Str.erase(Str.begin() + Str.find('0'));
		++RemoveZeroCount;
	}
}

// No Need to Clear Parameter Str, This Function Calls _Str.clear()
void ConvertLengthToBinaryStr(string& _Str)
{    
	int Length = static_cast<int>(_Str.size());
    _Str.clear();
    
    while (Length > 0)
	{
		_Str.insert(_Str.begin(),(Length % 2 == 0 ? '0' : '1'));
		Length /= 2;
	}
}

void RemoveZeroIfFirstIdx(string& _Str)
{
    if ('0' == _Str[0])
	{
		_Str.erase(_Str.begin());
	}
}

void ChangeBinary(string& Str)
{
	int Length = Str.size();
	if (1 == Length && '1' == Str[0])
	{
		return;
	}

	++CallChange;
    
	RemoveZero(Str);    
	ConvertLengthToBinaryStr(Str);
	RemoveZeroIfFirstIdx(Str);

	ChangeBinary(Str);
}

vector<int> solution(string Str) {
	vector<int> Answer;

	ChangeBinary(Str);
	Answer.push_back(CallChange);
	Answer.push_back(RemoveZeroCount);

	return Answer;
}
