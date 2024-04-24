#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int Day = 0;
	int Max_Day = 0;
	int FuncCount = progresses.size();
	for (int FuncIDX = 0; FuncIDX < FuncCount; ++FuncIDX)
	{
		// 일자는 현재 작업진척 / 날짜 + 1
		Day = ((99 - progresses[FuncIDX]) / speeds[FuncIDX]) + 1;

		if (answer.empty() || Max_Day < Day)
		{
			answer.push_back(1);
		}
		else
		{
			++answer.back();
		}

		if (Max_Day < Day)
		{
			Max_Day = Day;
		}
	}

	return answer;
}