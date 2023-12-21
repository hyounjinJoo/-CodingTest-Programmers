#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string A, string B) {   
    int answer = 0;
    int length = A.size();
    for(int index = 0; index < length; ++index)
    {
        if(A == B)
        {
            break;
        }
        rotate(A.begin(), A.end() - 1, A.end());
        ++answer;
        
    }
    if(A!=B)
    {
        answer = -1;
    }
    
    return answer;
}