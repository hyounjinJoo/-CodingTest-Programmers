#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define IDX_WORKTIME 1
struct TCmp
{
    bool operator()(vector<int> left, vector<int> right)
    {
        return left.at(IDX_WORKTIME) > right.at(IDX_WORKTIME);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, TCmp> PQueue;
    
    int IdxJob = 0;
    int Time = 0;
    int JobCount = jobs.size();
    while(IdxJob < JobCount || (false == PQueue.empty()))
    {
        if(JobCount > IdxJob && Time >= jobs[IdxJob][0])
        {
            PQueue.push(jobs[IdxJob++]);
            continue;
        }
        
        if(false == PQueue.empty())
        {
            Time += PQueue.top()[1];
            answer += Time - PQueue.top()[0];
            PQueue.pop();
            continue;
        }        
        
        Time = jobs[IdxJob][0];        
    }
    
    return answer / JobCount;
}