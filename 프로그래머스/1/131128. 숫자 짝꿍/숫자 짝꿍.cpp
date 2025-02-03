#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y) {
    // X, Y의 각 숫자에 해당하는 문자 갯수를 찾아낸다
    map<char, int> XMap;
    map<char, int> YMap;
    for(char CH : X) XMap[CH]++;
    for(char CH : Y) YMap[CH]++;
    
    string answer;
    // 문자의 키 값은 '0'~'9'인데, Pair를 이루려면 해당 키에 해당하는 값이 작은 쪽에 제한이 걸린다.
    // 가장 큰 수를 만들어야 하므로 '9'부터 짝궁의 갯수를 검사하여 숫자 문자열을 만들어준다. 
    for(char NUM = '9'; NUM >= '0'; --NUM)
    {
        int Count = min(XMap[NUM], YMap[NUM]);
        // Count의 갯수에 따라 반복하여 숫자를 붙여준다.
        for(int ITER = 0; ITER < Count; ++ITER)
        {
            answer += char(NUM);
        }
    }
    
    // 예외처리
    if(answer.empty())
    {
        answer = "-1";
    }
    else if(answer[0] == '0')
    {
        answer = "0";
    }
    
    return answer;
}