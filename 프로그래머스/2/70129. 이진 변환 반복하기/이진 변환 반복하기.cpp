#include <string>
#include <vector>

using namespace std;
int RemoveZeroCount = 0;
int CallChange = 0;
void ChangeBinary(string& Str)
{
	int Length = Str.size();

	if (1 == Length && '1' == Str[0])
	{
		return;
	}

	++CallChange;
	// 모든 0 제거
	while (string::npos != Str.find('0'))
	{
		Str.erase(Str.begin() + Str.find('0'));
		++RemoveZeroCount;
	}

	Length = Str.size();
	Str.clear();
	while (Length > 0)
	{
		Str.insert(Str.begin(),(Length % 2 == 0 ? '0' : '1'));
		Length /= 2;
	}

	if ('0' == Str[0])
	{
		Str.erase(Str.begin());
	}

	ChangeBinary(Str);
}

vector<int> solution(string Str) {
	vector<int> Answer;

	ChangeBinary(Str);
	Answer.push_back(CallChange);
	Answer.push_back(RemoveZeroCount);

	return Answer;
}