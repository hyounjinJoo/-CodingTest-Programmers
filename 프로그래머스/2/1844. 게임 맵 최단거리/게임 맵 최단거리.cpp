#include <vector>
#include <queue>
#include <utility>

using namespace std;

int M, N;
bool bIsVisit[101][101] = {0,};
int cost[101][101] = {0,};

int MoveX[4] = {1, 0, -1, 0};
int MoveY[4] = {0, 1,  0,-1};

queue<pair<int, int>> Queue;

#define StartPos 0, 0
#define Wall 0

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    N = maps[0].size();
    M = maps.size();
    
    Queue.push(make_pair(StartPos));
    bIsVisit[0][0] = true;
    cost[0][0] = 1;
    
    while(false == Queue.empty())
    {
        int CurX = Queue.front().first;
        int CurY = Queue.front().second;
        
        Queue.pop();
        
        int NextX = 0;
        int NextY = 0;
        bool CheckCanMove = false;
        for(int Dir = 0; Dir < 4; ++Dir)
        {
            NextX = CurX + MoveX[Dir];
            NextY = CurY + MoveY[Dir];
            
            CheckCanMove = NextX < 0 || NextX >= M || NextY < 0 || NextY >= N ? true : false;
            if(true == CheckCanMove)
            {
                continue;
            }
            
            CheckCanMove = bIsVisit[NextX][NextY];
            if(true == CheckCanMove)
            {
                continue;
            }
            
            CheckCanMove = (Wall == maps[NextX][NextY]);
            if(true == CheckCanMove)
            {
                continue;
            }
            
            bIsVisit[NextX][NextY] = true;
            Queue.push(make_pair(NextX, NextY));
            cost[NextX][NextY] = cost[CurX][CurY] + 1;            
        }
    }
    
    if(false == cost[M - 1][N - 1])
    {
        answer = -1;
    }
    else
    {
        answer = cost[M - 1][N - 1];
    }
    
    return answer;
}