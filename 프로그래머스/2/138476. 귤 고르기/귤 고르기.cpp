#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) 
{
    // 귤을 크기별로 분류하여 개수를 센다
    map<int, int> MapTangerine;
    for(int& Tan : tangerine)
    {
        ++MapTangerine[Tan];
    }
    
    // 상자에 개수가 많은 종류부터 담으면 
    // 상자에 담긴 종류가 최소화 되므로
    // 종류별 개수를 배열에 담아 내림차순으로 정렬해준다.
    vector<int> BigToSmallArray;
    for(auto Pair : MapTangerine)
    {
        BigToSmallArray.push_back(Pair.second);
    }
    
    sort(BigToSmallArray.begin(), BigToSmallArray.end(), greater<int>());
    
    int CountInBox = 0, Answer = 0;
    for(int IDX = 0; IDX < BigToSmallArray.size(); ++IDX)
    {
        // 상자에 담긴 귤 수가 k개 이상이면 꽉찼으니 정지
        if(CountInBox >= k)
        {
            break;
        }
        
        // 종류 수 더해주고
        // 현재 상자에 담긴 귤 수를 갱신한다.
        ++Answer;
        CountInBox += BigToSmallArray[IDX];
    }
    
    return Answer;
}