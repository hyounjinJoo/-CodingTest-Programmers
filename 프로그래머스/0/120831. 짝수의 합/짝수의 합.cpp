#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int number = 1; number <= n; ++number)
    {
        answer += (number % 2 == 0) ? number : 0;
    }
    
    return answer;
}