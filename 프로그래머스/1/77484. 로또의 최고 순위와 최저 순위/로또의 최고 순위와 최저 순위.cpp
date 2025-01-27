#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    // 효율적인 순차검색을 위한 정렬 수행
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int ZeroHit = 0;
    int NumberHit = 0;
    
    int NumberMaxCount = lottos.size();
    for(int Index = 0; Index < NumberMaxCount; ++Index)
    {
        if(lottos[Index] == 0)
        {
            ++ZeroHit;
            continue;
        }
        
        for(int WinNumIndex = 0; WinNumIndex < NumberMaxCount; ++WinNumIndex)
        {
            if(lottos[Index] == win_nums[WinNumIndex])
            {
                ++NumberHit;
                break;
            }
        }
    }
    
    // 전부 다 틀렸을 경우 6등이 나오기 위한 예외처리
    if(ZeroHit == 0 && NumberHit == 0)
    {
        ++NumberHit;
    }
    answer.push_back(7-(ZeroHit + NumberHit));
    
    // 모두 지워진 경우 6등이 나오기 위한 예외처리
    if(NumberHit == 0 && ZeroHit == 6)
    {
        ++NumberHit;
    }
    answer.push_back(7-(NumberHit));
    
    return answer;
}