#include <string>
#include <vector>

using namespace std;


long long Fibonazzi(long long n);
long long Fibonazzi_Tail(long long n);

long long Fibonazzi(long long n)
{
    return Fibonazzi_Tail(n);
}

long long Fibonazzi_Tail(long long n)
{
    if(0 == n)
    {
        return 0;
    }
    else if(1 == n)
    {
        return 1;
    }
    else
    {
        return Fibonazzi_Tail(n - 1) + Fibonazzi_Tail(n - 2);
    }
}


long long solution(int n) {
    vector<long long> FibonazziARR;
    FibonazziARR.push_back(1);
    FibonazziARR.push_back(1);
    long long Temp = 0;
    for(int Idx = 2; Idx <= n; ++Idx)
    {
        Temp = (FibonazziARR[Idx - 1] + FibonazziARR[Idx - 2]) % 1234567;
        FibonazziARR.push_back(Temp);
    }
    
    return FibonazziARR[n];
}