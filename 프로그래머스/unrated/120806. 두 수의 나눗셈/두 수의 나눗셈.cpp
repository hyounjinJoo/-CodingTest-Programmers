#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    
    float quotient = static_cast<float>(num1);
    quotient /= static_cast<float>(num2);

    //값에 1,000을 곱
    answer = static_cast<int>(quotient * 1000);
    
    return answer;
}