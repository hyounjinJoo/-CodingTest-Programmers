#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    char FirstAlphabet = s[0];
    size_t Same = 0;
    size_t Diff = 0;
    size_t Length = s.length();
    
    int Answer = 0;
    for(int IDX = 0; IDX < Length; ++IDX)
    {        
        FirstAlphabet == s[IDX] ? ++Same : ++Diff;
        if(Same == Diff)
        {
            Same = 0;
            Diff = 0;
            ++Answer;
            
            if(IDX + 1 < Length) FirstAlphabet = s[IDX + 1];            
        }
        
        if(Same >= 1 && IDX + 1 == Length)
        {
            ++Answer;
        }
    }
    
    return Answer;
}