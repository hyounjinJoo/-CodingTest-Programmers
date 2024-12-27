#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    long long Value = x;
    // n개에 도달할 때까지 반복을 하면 된다.
    for(int Iter = 0; Iter < n; ++Iter)
    {
        answer.push_back(Value);
        Value += x;        
    }
    
    return answer;
}