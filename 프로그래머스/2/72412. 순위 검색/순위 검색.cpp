#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, vector<int>> PassCases;

void AddCases(const string* const _InWords, int _InScore)
{
	string ConditionKey;
	int MinusDesicionValue = 0;
	for (int Case = 0; Case < 16; ++Case)
	{
		ConditionKey.clear();
		MinusDesicionValue = Case;
		for (int Place = 0; Place < 4; ++Place)
		{
			if (MinusDesicionValue <= 0 || MinusDesicionValue % 2 == 0) ConditionKey += "-";
			else ConditionKey += _InWords[Place];
			MinusDesicionValue /= 2;
		}

		PassCases[ConditionKey].push_back(_InScore);
	}
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> Answer;
	
	string Tokens[4], TempStr;

	int InfosSize = info.size();
	for (int Idx = 0; Idx < InfosSize; ++Idx)
	{
		istringstream STT(info[Idx]);
		for (int TokenIdx = 0; TokenIdx < 4; ++TokenIdx)
		{
			STT >> Tokens[TokenIdx];
		}
		STT >> TempStr;

		AddCases(Tokens, static_cast<int>(stoi(TempStr)));
	}

	for (auto Iter = PassCases.begin(); Iter != PassCases.end(); ++Iter)
	{
		sort(Iter->second.begin(), Iter->second.end());
	}

	int QuerySize = query.size();
	for (int Idx = 0; Idx < QuerySize; ++Idx)
	{
		istringstream STT(query[Idx]);
		for (int TokenIdx = 0; TokenIdx < 4; ++TokenIdx)
		{
			STT >> Tokens[TokenIdx] >> TempStr;
		}
		int Score = static_cast<int>(stoi(TempStr));

		string CurrentQueryKey = Tokens[0] + Tokens[1] + Tokens[2] + Tokens[3];
		vector<int> TempVector = PassCases[CurrentQueryKey];
		if (!TempVector.empty())
		{
			int Idx = lower_bound(TempVector.begin(), TempVector.end(), Score) - TempVector.begin();
			Answer.push_back(TempVector.size() - Idx);
		}
		else
		{
			Answer.push_back(0);
		}
	}

	return Answer;
}