#include <string>
#include <vector>

using namespace std;

int FindGCD(int num1, int num2)
{
    while(num2 > 0)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    
    return num1;
}

int FindLCM(int num1, int num2)
{
    return (num1 * num2) / FindGCD(num1, num2);
}


int solution(int n) {
    int answer = FindLCM(n, 6) / 6;
    return answer;
}