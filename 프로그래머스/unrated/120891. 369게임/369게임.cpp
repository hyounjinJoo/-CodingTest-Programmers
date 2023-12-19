#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int remain = 0;    
    int answer = 0;
    
    for(; order != 0;)
    {
        remain = order % 10;
        order /= 10;
        if(remain == 3 || remain == 6 || remain == 9)
        {
            ++answer;
        }
    }    
    
    return answer;
}