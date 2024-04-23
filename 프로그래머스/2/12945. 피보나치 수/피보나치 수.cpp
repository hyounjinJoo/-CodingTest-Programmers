#include <string>
#include <vector>

using namespace std;
int memo[100001];

int solution(int n) {
    int answer = 0;
    
    memo[0] = 0;
    memo[1] = 1;
    
    for(int F = 2; F <= n; ++F)
    {
        memo[F] = (memo[F - 2] + memo[F - 1]) % 1234567;
    }
    
    answer = memo[n];
    
    return answer;
}