#include <vector>
#include <algorithm>

using namespace std;

bool compare(int Left, int Right)
{
    return Left >= Right;
}

long long solution(long long n) 
{
    long long answer = 0;
    std::vector<long long> Vector;
    while(n > 0)
    {
        Vector.push_back(n % 10);
        n /= 10;
    }
    
    sort(Vector.begin(), Vector.end(), compare);
    for(long long Number : Vector)
    {
        answer += Number;
        answer *= 10;
    }
    
    answer /= 10;
    
    return answer;
}