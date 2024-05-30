#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> CharStack;
    char CurrentTopChar = '\0';
    int Size = s.size();
    for(int Idx = 0; Idx < Size; ++Idx)
    {
        // 이전 Stack의 탑이 존재할 때
        if('\0' != CurrentTopChar)
        {
            // 탑 문자열과 지금 넣으려고 하는 것이 같으면 지울 것이므로
            // 지우고,
            // 스택의 top이 존재하면 CurrentTopChar를 변경
            // continue
            if(CurrentTopChar == s[Idx])
            {
                if(0 < CharStack.size())
                {
                    CharStack.pop();
                    if(false == CharStack.empty())
                    {                   
                        CurrentTopChar = CharStack.top();
                    }
                    else
                    {
                        CurrentTopChar = '\0';
                    }
                }
            }
            // 아니면, 그냥 push하고 CurrentTopChar 수정
            else
            {
                CharStack.push(s[Idx]);
                CurrentTopChar = s[Idx];                
            }            
        }
        else
        {            
            CharStack.push(s[Idx]);
            CurrentTopChar = s[Idx];    
        }
    }
    
    if(CharStack.empty())
    {
        answer = 1;
    }
    
    return answer;
}

// 첫번째 고민
/*
int solution(string s)
{
    // 문자가 들어온다
    // 들어온 문자가 이전 문자와 다른가?
    // Y : 새로운 문자 시작
    // 들어온 문자가 이전 문자와 동일한가?
    // Y : 삭제할 준비가 되었다.
    // 들어온 문자가 이전 문자와 다른가?
    // Y : 인덱스를 -2만큼 이전으로 바꾼다.
    // 삭제된 문자열이 있다면 다시 반복을 수행한다.
    string Test;
    bool bNeedRepeat = false;
    int Limit = s.size() - 1;
    char PrevChar = NULL;
    bool bFirstNotEqual = false;
    bool bSecondEqual = false;
    bool bThirdNotEqual = false;
    for(int Idx = 0; true == bNeedRepeat; ++Idx)
    {
        if(NULL == PrevChar && 0 == Idx)
        {
            PrevChar = s[Idx];
            
        }
        
        if((Idx == Limit) && true == bNeedRepeat)
        {
            Idx = 0;
            s = Test;
            
            if(true == s.empty())
            {
                answer = 1;
                break;
            }
            
            Test.clear();
            Limit = s.size() - 1;
            PrevChar = NULL;
            
            bFirstNotEqual = false;
            bSecondEqual = false;
            bThirdNotEqual = false;
        }
    }
}
*/