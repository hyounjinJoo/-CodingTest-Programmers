#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 7조각으로 잘라준다.
    // n이 주어진다.
    // 7 / 7 = 1, 7 % 7 = 0
    // 7 / 1 = 7, 7 % 1 = 0
    // 7 / 15 = 0.4?, 7 % 15 = 7
    float a = 7.f;
    float b = static_cast<float>(n);
    
    float c = a / b;
    
    int pan = 1;
    if( c < 1.f)
    {
        // c의 역을 구한다.
        int quotient = n / 7;
        int left = n % 7;
        if(left != 0)
        {
            quotient += 1;
        }
        
        pan = quotient;
    }
    
    answer = pan;
    return answer;
}