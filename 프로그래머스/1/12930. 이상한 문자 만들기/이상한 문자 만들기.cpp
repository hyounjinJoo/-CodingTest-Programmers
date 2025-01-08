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
            WordIDX = 0;
            continue;
        }
        
        for(int AlphabetIDX = IDX + WordIDX; AlphabetIDX < length && s[AlphabetIDX] != ' '; ++AlphabetIDX)
        {
            if(WordIDX++ % 2 == 0)
            {
                s[AlphabetIDX] = toupper(s[AlphabetIDX]);
            }
            else
            {
                s[AlphabetIDX] = tolower(s[AlphabetIDX]);
            }
        }
    }
    
    answer = s;
    
    return answer;
}