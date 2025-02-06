#include <string>
#include <vector>
#include <limits>

using namespace std;

constexpr int INT_MAX = numeric_limits<int>::max();

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // targets[0]를 대상으로 생각해보면
    // 문자 1개가 각 키맵의 버튼을 대상으로 가장 작은 입력횟수를 찾아 입력횟수에 더해나간다.
    // 만약 가장 작은 입력횟수를 찾아나갈 때, 해당하는 키가 존재하지 않는다면 targets의 해당 원소는 완성될 수 없다.
    for(string& Target : targets)
    {
        int TargetTotalCount = 0;
        for(int TargetAlphaIDX = 0; TargetAlphaIDX < Target.length(); ++TargetAlphaIDX)
        {
            // 문자 1개씩 keymap의 각 원소에서 가장 작은 입력 횟수를 찾아나간다.
            int InputCount = INT_MAX;
            for(string& Key : keymap)
            {
                for(int IDX = 0; IDX < Key.length(); ++IDX)
                {
                    if(Key[IDX] == Target[TargetAlphaIDX])
                    {
                        if(IDX + 1 < InputCount)
                        {
                            InputCount = IDX + 1;
                        }
                        break;
                    }
                }
            }
            
            // 갱신이 안 되었다면 이 Target은 완성할 수 없다.
            if(InputCount == INT_MAX)
            {
                TargetTotalCount = -1;
                break;
            }
            
            TargetTotalCount += InputCount;
        }
        
        answer.push_back(TargetTotalCount);
    }
    return answer;
}