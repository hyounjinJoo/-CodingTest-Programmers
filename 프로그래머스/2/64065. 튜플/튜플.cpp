#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void StringToVectors(const string& _InStr, vector<vector<int>>& _InVector)
{
	int Length = _InStr.length() - 1;
	vector<int> Numbers;
	bool bNumberInput = false;
	string NumberStr;
	for (int Pos = 1; Pos < Length; ++Pos)
	{
        char Char = _InStr[Pos];
        
		if (Char == '}')
		{
			if (bNumberInput)
			{
				Numbers.push_back(std::stoi(NumberStr));
				NumberStr.clear();
			}

			++Pos;
			_InVector.push_back(Numbers);
			bNumberInput = false;
		}
		else if (Char == '{')
		{
			bNumberInput = true;
			Numbers.clear();
		}
		else if (Char == ',' && bNumberInput)
		{
			NumberStr += Char;
			Numbers.push_back(std::stoi(NumberStr));
			NumberStr.clear();
		}
		else
		{
			NumberStr+= Char;
		}
	}

	return;
}

bool FindNumber(const int& _InNumber, const vector<int>& _InNumbers)
{
	bool bFound = false;
	int Size = _InNumbers.size();
	for (int Idx = 0; Idx < Size; ++Idx)
	{
		if (_InNumber == _InNumbers[Idx])
		{
			bFound = true;
			break;
		}
	}
	
	return bFound;
}

bool Sort(const vector<int>& _InLeft, const vector<int>& _InRight)
{
	return _InLeft.size() <= _InRight.size();
}

vector<int> solution(string _InStr) {
	vector<int> Answer;
	vector<vector<int>> Temp;
	StringToVectors(_InStr, Temp);

	sort(Temp.begin(), Temp.end(), Sort);

	for (int Idx = 0; Idx < Temp.size(); ++Idx)
	{
		for (int Number : Temp[Idx])
		{
			if (false == FindNumber(Number, Answer))
			{
				Answer.push_back(Number);
			}
		}
	}

	return Answer;
}