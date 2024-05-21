#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 약수의 갯수 구하기
    for(int Num = 2; Num < n; ++Num)
    {
        if((false == (n % Num)) && (Num & 1))
        {
            ++answer;
        }
    }
    answer += (n & 1) ? 2 : 1;
    if(1 == n)
    {
        answer = 1;
    }
    
    return answer;
}