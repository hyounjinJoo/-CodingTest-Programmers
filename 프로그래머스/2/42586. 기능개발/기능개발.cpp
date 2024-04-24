#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int developeCount = progresses.size();

	while (false == progresses.empty())
	{
		for (int funcIDX = 0; funcIDX < developeCount; ++funcIDX)
		{
			if (100 > progresses[funcIDX])
			{
				progresses[funcIDX] += speeds[funcIDX];
				if (100 < progresses[funcIDX])
				{
					progresses[funcIDX] = 100;
				}
			}
		}
		// 작업진행이 101인 경우 배열 순회하여 answer에 넣을 값 증가 후 제거
		if (101 == progresses[0])
		{
			int publishFunction = 0;
			while (101 == progresses[0])
			{
				++publishFunction;
				--developeCount;

				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());

				if (true == progresses.empty())
				{
					break;
				}
			}
			answer.push_back(publishFunction);
		}

		for (int funcIDX = 0; funcIDX < developeCount; ++funcIDX)
		{
			if (100 == progresses[funcIDX])
			{
				progresses[funcIDX] = 101;
			}
		}
	}

	return answer;
}