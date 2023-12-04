#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int number = 1; number <= n; ++number)
    {
        if(n % number == 0)
        {
            ++answer;
        }
    }
    return answer;
}