#include <string>

using namespace std;

string solution(string s, int n) 
{    
    string answer = "";
    size_t length = s.size();
    // 문자를 한 개씩 바꿔나간다.    
    int changed = 0;
    for(size_t IDX = 0; IDX < length; ++IDX)
    {
        // 공백은 밀 수 없다.
        if(s[IDX] == ' ')
        {
            continue;
        }
        // n만큼 민다.
        changed = s[IDX] + n;
        // z를 넘어가면 소문자는 다시 소문자가 된다.
        if('z' < changed && s[IDX] <= 'z')
        {
            changed -= 26;
        }
        // Z를 넘어가면 대문자는 다시 대문자가 된다.
        else if('Z' < changed && s[IDX] <= 'Z')
        {
            changed -= 26;
        }
        
        // 바뀐 문자를 다시 문자열에 반영한다.
        s[IDX] = static_cast<char>(changed);
    }
    
    answer = s;
    return answer;
}