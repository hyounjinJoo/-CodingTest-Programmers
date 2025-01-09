#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    // t에서...
    //     부분 문자열의 길이는 p의 길이와 같고
    //         부분 문자열과 p의 값 중 부분 문자열이 더 작은 경우의 횟수를 구한다.
    size_t LengthT = t.length();
    size_t LengthP = p.length();
    long long ValueP = stol(p);
    
    for(size_t IDX = 0; IDX + LengthP <= LengthT; ++IDX)
    {
        long long ValueT = stol(string(t.substr(IDX, LengthP)));
        
        if(ValueT <= ValueP)
        {
            ++answer;
        }
    }
    
    return answer;
}