#include <vector>

using namespace std;

long long solution(int n)
{
    // 한 번에 1칸 혹은 2칸을 뛸 수 있다.
    // 칸이 총 1칸이면
    // 경우의 수는 1로 1개
    // 칸이 2칸이면
    // 경우의 수는 1-1, 2로 2개
    // 칸이 3칸이면
    // 경우의 수는 1-1-1, 1-2, 2-1 => 3개
    // 칸이 4칸이면
    // 경우의 수는 1-1-1-1, ... 예시와 동일 => 5개
    // 칸이 5칸이면
    // 경우의 수는 8개
    // 1-1-1-1-1
    // 1-1-1-2
    // 1-1-2-1
    // 1-2-1-1
    // 1-2-2
    // 2-1-1-1
    // 2-1-2
    // 2-2-1
    // 즉, f(n) = f(n - 2) + f(n - 1)가 되는 경향을 뛴다.
        
    vector<long long> Fibonazzi(n + 1);
    
    Fibonazzi[0] = 1;
    Fibonazzi[1] = 1;
    for(int IDX = 2; IDX <= n; ++IDX)
    {
        Fibonazzi[IDX] = (Fibonazzi[IDX - 2] + Fibonazzi[IDX -1]) % 1234567;
    }
    
    return Fibonazzi[n];
}