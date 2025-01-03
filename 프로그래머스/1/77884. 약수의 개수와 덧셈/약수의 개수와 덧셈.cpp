#include <string>
#include <vector>

using namespace std;

int FindAndCountDivisor(int number)
{
    int result = 0;
    for(int divisor = 1; divisor <= number; ++divisor)
    {
        if(number % divisor == 0)
        {
            ++result;
        }
    }
    
    return result;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int number = left; number <= right; ++number)
    {
        answer += FindAndCountDivisor(number) % 2 == 0 ? number : -number;        
    }
    
    return answer;
}