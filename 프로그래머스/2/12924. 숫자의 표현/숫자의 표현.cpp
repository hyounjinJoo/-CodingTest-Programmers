#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int Num = 1; Num < n + 1; ++Num)
    {
        if(n % Num == 0)
        {
            if(Num % 2 == 1)
            {
                ++answer;
            }
        }
    }
    
    return answer;
}