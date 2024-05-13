#include <string>
#include <vector>

using namespace std;

#define MAXDUNGEON 8
#define VISIT true
#define NEEDVISIT false

int Answer = 0;
bool Visited[MAXDUNGEON] = {0};

void DFS(int _Count, int _CurTired, vector<vector<int>>& _Dungeons) {
    if (_Count > Answer) 
    {
        Answer = _Count;
    }
    
    int DungeonsSize = _Dungeons.size();
    for (int Idx = 0; Idx < DungeonsSize; ++Idx) 
    {        
        if ((NEEDVISIT == Visited[Idx]) && (_Dungeons[Idx][0] <= _CurTired))
        {
            Visited[Idx] = VISIT;
            DFS(_Count + 1, _CurTired - _Dungeons[Idx][1], _Dungeons);
            // This Dungeon's DFS is ended.
            
            Visited[Idx] = NEEDVISIT;
        }
    }
}

int solution(int _CurTired, vector<vector<int>> _Dungeons) {
    DFS(0, _CurTired, _Dungeons);
    
    return Answer;
}