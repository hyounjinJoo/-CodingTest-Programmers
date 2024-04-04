#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQueue(scoville.begin(), scoville.end());
    
    while(PQueue.size() > 1 && PQueue.top() < K)
    {
        int left = PQueue.top();
        PQueue.pop();
        int right = PQueue.top();
        PQueue.pop();
        
        PQueue.push(left + (right * 2));
        answer++;
    }
    
    if(PQueue.top() < K)
    {
        answer = -1;
    }
    
    return answer;
}