#include <string>
#include <vector>

using namespace std;

#define MAX 200+1

bool bIsVisit[MAX];

void DFS(int CurrentIDX, int MaxNumber, vector<vector<int>> Computers)
{
    bIsVisit[CurrentIDX] = true;
    
    for(int Index = 0; Index < MaxNumber; ++Index)
    {
        if((0 == bIsVisit[Index]) && (1 == Computers[CurrentIDX][Index]))
        {
            DFS(Index, MaxNumber, Computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int Index = 0; Index < n; ++Index)
    {
        if(0 == bIsVisit[Index])
        {
            DFS(Index, n, computers);
            
            ++answer;
        }
    }
    
    return answer;
}