#include <string>
#include <vector>

using namespace std;

void Divide(vector<int>& quotientVec, int num)
{
    
    
    Divide(quotientVec, num);
}

vector<int> solution(int n) {
    vector<int> answer;
    
    
    int newNumerator = n;
    for(int denom = 2; newNumerator != 1; ++denom)
    {
        if(newNumerator % denom == 0)
        {
            newNumerator = static_cast<int>(newNumerator / denom);
            
            bool findResult = false;
            auto iterBegin = answer.begin();
            auto iterEnd = answer.end();
            for(; iterBegin != iterEnd; ++iterBegin)
            {
                if(*iterBegin == denom)
                {
                    findResult = true;
                }
            }
            
            if(false == findResult)
            {                
                answer.push_back(denom);
            }
            
            denom = 1;
        }
    }
    
    return answer;
}