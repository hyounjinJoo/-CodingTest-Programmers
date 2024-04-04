#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQueue(scoville.begin(), scoville.end());
    
    int Mixed = 0;
    while(PQueue.size() > 1 && PQueue.top() < K)
    {
        Mixed = PQueue.top();
        PQueue.pop();
        Mixed = Mixed + (2 * PQueue.top());
        PQueue.pop();

        PQueue.push(Mixed);
        answer++;
    }
    
    if(PQueue.top() < K)
    {
        answer = -1;
    }
    
    return answer;
}