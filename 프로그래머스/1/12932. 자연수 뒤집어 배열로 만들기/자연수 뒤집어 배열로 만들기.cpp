#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    // 마지막 자릿수부터 배열에 넣어주면 된다.
    while(n > 0)
    {
        answer.push_back(n % 10);
        n /= 10;
    }
    
    return answer;
}