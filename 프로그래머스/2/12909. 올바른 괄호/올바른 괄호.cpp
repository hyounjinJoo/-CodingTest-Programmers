#include<string>
#include<vector>

using namespace std;

bool solution(string s)
{
    bool Answer = false;
    vector<char> Stack;
    
    int Length = s.length();
    char Temp;
    for(int Idx = 0; Idx < Length; ++Idx)
    {
        Temp = s[Idx];
        
        if('(' == Temp)
        {
            Stack.push_back(Temp);
        }
        else if(')' == Temp)
        {
            if(0 == Stack.size())
            {
                Stack.push_back(Temp);
            }
            else
            {
                if('(' == Stack.back())
                {
                    Stack.pop_back();
                }
                else
                {
                    Stack.push_back(Temp);
                }
            }
        }        
    }
    
    if(0 == Stack.size())
    {
        Answer = true;
    }
    
    return Answer;
}