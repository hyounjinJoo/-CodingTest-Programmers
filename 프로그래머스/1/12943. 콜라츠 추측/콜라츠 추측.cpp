#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long changedNum = num;
    if(changedNum == 1)
    {
        return 0;
    }
    
    int answer = -1;    
    
    for(int Iter = 1; Iter <= 500; ++Iter)
    {
        if(changedNum % 2 == 0)
        {
            changedNum /= 2;
        }
        else
        {
            changedNum = changedNum * 3 + 1;
        }
        
        if(changedNum == 1)
        {
            answer = Iter;
            break;
        }        
    }
    
    return answer;
}