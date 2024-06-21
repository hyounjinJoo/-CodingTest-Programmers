#include <string>
#include <vector>

using namespace std;

int FindGCD(int a, int b);

int GCD(int a, int b)
{
    int Max = max(a, b);
    int Min = min(a, b);
    
    return FindGCD(Max, Min);
}

int FindGCD(int a, int b)
{
    int R = a % b;
        
    if(0 == R)
    {
        return b;
    }
    else
    {
        return FindGCD(b, R);
    }
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    int Lcm = 0;    
    int Size = arr.size();
    for(int Idx = 1; Idx < Size; ++Idx)
    {
        Lcm = LCM(answer, arr[Idx]);
        answer = Lcm;
    }
    
    return answer;
}