#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Map;

void DFS(int x, int y, int Size, vector<int>& answer)
{
    bool Zero, One;
    Zero = One = true;
    
    for(int i = x; i < x + Size; ++i)
    {
        for(int j = y; j < y + Size; ++j)
        {
            if(0 == Map[i][j]) One = false;
            if(1 == Map[i][j]) Zero = false;
        }
    }
    
    if(true == Zero)
    {
        ++answer[0];
        return;
    }
    
    if(true == One)
    {
        ++answer[1];
        return;
    }
    
    size_t NextSize = Size / 2;
    
    DFS(x           , y             , NextSize, answer);
    DFS(x           , y + NextSize  , NextSize, answer);
    DFS(x + NextSize, y             , NextSize, answer);
    DFS(x + NextSize, y + NextSize  , NextSize, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    Map = arr;
    DFS(0, 0, Map.size(), answer);
    
    return answer;
}