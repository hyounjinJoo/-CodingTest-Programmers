#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    
    int quotient = n / slice;
    int left = n % slice;
    
    if(0 != left)
    {
        quotient++;
    }
    
    answer = quotient;
    
    return answer;
}