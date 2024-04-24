#include <string>
#include <vector>

using namespace std;
#define DevelopeEnd 100
#define ReadyToPublish 101
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int developeCount = progresses.size();

	while (false == progresses.empty())
	{
		for (int funcIDX = 0; funcIDX < developeCount; ++funcIDX)
		{
			if (DevelopeEnd > progresses[funcIDX])
			{
				progresses[funcIDX] += speeds[funcIDX];
				if (DevelopeEnd < progresses[funcIDX])
				{
					progresses[funcIDX] = DevelopeEnd;
				}
			}
		}
		// 작업진행이 ReadyToPublish(=101)인 경우 배열 순회하여 answer에 넣을 값 증가 후 제거
		if (ReadyToPublish == progresses[0])
		{
			int PublishCount = 0;
			while (ReadyToPublish == progresses[0])
			{
				++PublishCount;
				--developeCount;

				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());

				if (true == progresses.empty())
				{
					break;
				}
			}
			answer.push_back(PublishCount);
		}

        // 배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정
		for (int funcIDX = 0; funcIDX < developeCount; ++funcIDX)
		{
			if (DevelopeEnd == progresses[funcIDX])
			{
				progresses[funcIDX] = ReadyToPublish;
			}
		}
	}

	return answer;
}