#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    for(int integer = 0; integer < 1001; ++integer)
    {
        if(n == integer * integer)
        {
            answer = 1;
        }
    }
    
    return answer;
}