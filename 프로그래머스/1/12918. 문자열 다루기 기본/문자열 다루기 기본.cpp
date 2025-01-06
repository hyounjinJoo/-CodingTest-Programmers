#include <string>

using namespace std;

bool solution(string s) {
    bool answer = false;
    {// 문자열의 길이가 4혹은 6인가?
        answer = s.size() == 4 || s.size() == 6 ? true : false;
    }
    
    {// 문자열 내에 숫자가 아닌 것이 존재하는가?
        for(size_t IDX = 0; IDX < s.size(); ++IDX)
        {
            if(s[IDX] < '0'  || '9' < s[IDX])
            {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}