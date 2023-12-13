#include <string>
#include <vector>
#include <limits>

using namespace std;

int solution(int n) {
    int answer = 1;
    int value = 1;
    int limitRange = std::numeric_limits<int>::max();
    
    for(int iter = 1; iter <= limitRange; ++iter)
    {
        value *= iter;
        if(n < value)
        {
            answer = iter - 1;
            break;
        }
        else if(n == value)
        {
            answer = iter;
            break;
        }
    }
    
    return answer;
}