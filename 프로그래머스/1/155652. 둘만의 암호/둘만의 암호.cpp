#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    //문자열 s의 각 알파벳을 index만큼 뒤의 알파벳으로 바꿔줍니다.
    //index만큼의 뒤의 알파벳이 z를 넘어갈 경우 다시 a로 돌아갑니다.
    //skip에 있는 알파벳은 제외하고 건너뜁니다.
    
    /*
    5 ≤ s의 길이 ≤ 50
    1 ≤ skip의 길이 ≤ 10
    s와 skip은 알파벳 소문자로만 이루어져 있습니다.
    skip에 포함되는 알파벳은 s에 포함되지 않습니다.
    1 ≤ index ≤ 20
    */
    
    for(char& ch : s)
    {
        for(int Idx = 0; Idx < index; ++Idx)
        {
            ch ++;

            if('z' < ch) ch = 'a';
            
            while(skip.find(ch) != string::npos)
            {
                ch++;
                if('z' < ch) ch = 'a';
            }
        }
    }
    
    return s;
}