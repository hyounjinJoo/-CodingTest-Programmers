#include <string>
#include <vector>

using namespace std;

#define UPPER ('a'-'A')

inline bool IsDigit(const char& _Char)
{
    bool result = false;
    if('0' <= _Char && _Char <= '9')
    {
        result = true;
    }
    
    return result;
}

inline bool IsUpper(const char& _Char)
{
    bool result = false;
    if('a' <= _Char && _Char <= 'z')
    {
        result = true;
    }
    
    return result;
}

string solution(string Str) {
    string Answer = "";
    bool bIsInside = false;
    
    for(const char& _char : Str)
    {
        if(' ' == _char)
        {
            Answer += ' ';
            bIsInside = false;
        }
        else if(false == bIsInside)
        {
            Answer += toupper(_char);
            bIsInside = true;
        }
        else
        {
            Answer += tolower(_char);
        }
    }
    
    return Answer;
}