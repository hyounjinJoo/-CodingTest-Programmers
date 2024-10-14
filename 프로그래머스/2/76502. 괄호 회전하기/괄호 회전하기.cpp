#include <string>
#include <vector>
#include <stack>

using namespace std;



void ShiftLeft(string& Str)
{
    string TempStr = Str.substr(1, Str.size()) + Str.substr(0, 1);
    Str = TempStr;
}

bool CheckBraceOpen(const char& letter)
{
    if(letter == '[' || letter == '(' || letter == '{')
    {
        return true;
    }
    
    return false;
}

int solution(string s) {
    int answer = 0;
    
    int ShiftMax = s.size();
    for(int ShiftIter = 0; ShiftIter < ShiftMax; ++ShiftIter)
    {
        stack<char> TempStack;
        bool Flag = false;
        for(int LetterIDX = 0; LetterIDX < ShiftMax; ++LetterIDX)
        {
            if(CheckBraceOpen(s[LetterIDX]))
            {
                Flag = true;
                TempStack.push(s[LetterIDX]);
            }
            else
            {
                if(s[LetterIDX] == ']' && TempStack.top() == '[')
                    TempStack.pop();
                if(s[LetterIDX] == '}' && TempStack.top() == '{')
                    TempStack.pop();
                if(s[LetterIDX] == ')' && TempStack.top() == '(')
                    TempStack.pop();
            }
        }
        
        if(TempStack.empty() && Flag) ++answer;
        
        ShiftLeft(s);   
    }
    
    return answer;
}