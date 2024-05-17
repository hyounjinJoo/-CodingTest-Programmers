#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int Answer = 0;
    
    map<int, int> TanMap;
    for(int Tan : tangerine)
    {
        ++TanMap[Tan];
    }
    
    vector<int> ForSort;
    for(auto Pair : TanMap)
    {
        ForSort.push_back(Pair.second);
    }
    
    sort(ForSort.begin(), ForSort.end(), greater<int>());
    
    int Count = 0;
    for(int Idx = 0; Idx < ForSort.size(); ++Idx)
    {
        if(Count >= k)
        {
            break;
        }
        
        ++Answer;
        Count += ForSort[Idx];
        
    }
    
    return Answer;
}