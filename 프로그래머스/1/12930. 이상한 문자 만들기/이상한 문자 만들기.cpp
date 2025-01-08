#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int length = s.length();
    int WordIDX = 0;
    for(int IDX = 0; IDX < length; ++IDX)
    {        
        // 공백이 나오면 다음 단어가 시작하는 인덱스로 이동
        if(s[IDX] == ' ')
        {
            WordIDX = IDX + 1;
            continue;
        }
        
        if((IDX - WordIDX) % 2 == 0)
        {
            s[IDX] = toupper(s[IDX]);
        }
        else
        {
            s[IDX] = tolower(s[IDX]);
        }
            
    }
    
    answer = s;
    
    return answer;
}