#include <string>
#include <vector>

using namespace std;

int GetNumbersSum(int x)
{
    int Sum = 0;
    while(x > 0)
    {
        Sum += x % 10;
        x /= 10;
    }
    
    return Sum;
}

bool solution(int x) {
    bool answer = false;
    int Sum = GetNumbersSum(x);
    
    if(x % Sum == 0)
    {
        answer = true;
    }
    
    return answer;
}