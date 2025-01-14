#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.length(), -1);
    
    
    for(int IDX = 0; IDX < s.length(); ++IDX)
    {
        bool bFind = false;
        for(int FindIDX = IDX - 1; FindIDX >= 0; --FindIDX)
        {
            if(s[FindIDX] == s[IDX])
            {
                bFind = true;
                answer[IDX] = IDX - FindIDX;
                break;
            }
        }
        
        if(!bFind)
        {
            answer[IDX] = -1;
        }        
    }
    
    return answer;
}