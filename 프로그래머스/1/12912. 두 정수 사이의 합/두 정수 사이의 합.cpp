long long GetSumRange(int min, int max)
{
    if(min == max)
    {
        return min;
    }
    
    long long Sum = 0;
    for(long long Number = min; Number <= max; ++Number)
    {
        Sum += Number;
    }
    
    return Sum;
}

inline int min(int a, int b)
{
    return a > b ? b : a;
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}

long long solution(int a, int b) {
    long long answer = GetSumRange(min(a, b), max(a, b));
    return answer;
}