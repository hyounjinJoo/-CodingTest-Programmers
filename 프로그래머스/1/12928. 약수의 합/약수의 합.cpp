#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 약수 구하는 방법
    // 1부터 해당 숫자를 나누기 시작한다.
    // 나누어 나머지가 없는 숫자를 찾는다.
    for(int Number = 1; Number <= n; ++Number)
    {
        // 해당 회차의 숫자와 n을 나머지 연산 후 0이면 해당 약수를 더한다.
        if(n % Number == 0)
        {
            answer += Number;
        }
    }
    
    return answer;
}