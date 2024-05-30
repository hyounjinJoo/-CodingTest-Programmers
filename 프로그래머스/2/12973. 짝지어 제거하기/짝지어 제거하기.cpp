#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> CharStack;
    
    int Size = s.size();
    for(int Idx = 0; Idx < Size; ++Idx)
    {
        if(false == CharStack.empty() && CharStack.top() == s[Idx])
        {             
            CharStack.pop();
        }
        else
        {            
            CharStack.push(s[Idx]);  
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