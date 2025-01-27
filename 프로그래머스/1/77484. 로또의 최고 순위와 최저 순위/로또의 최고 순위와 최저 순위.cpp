#include <string>
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
    for(int Index = 0; Index < lottos.size(); ++Index)
    {
        if(lottos[Index] == 0)
        {
            ++ZeroHit;
            continue;
        }
        
        for(int WinNumIndex = 0; WinNumIndex < win_nums.size(); ++WinNumIndex)
        {
            if(lottos[Index] == win_nums[WinNumIndex])
            {
                ++NumberHit;
                break;
            }
        }
    }
    
    if(ZeroHit == 0 && NumberHit == 0)
    {
        ++NumberHit;
    }
    answer.push_back(7-(ZeroHit + NumberHit));
    if(NumberHit == 0 && ZeroHit == 6)
    {
        ++NumberHit;
    }
    answer.push_back(7-(NumberHit));
    
    return answer;
}