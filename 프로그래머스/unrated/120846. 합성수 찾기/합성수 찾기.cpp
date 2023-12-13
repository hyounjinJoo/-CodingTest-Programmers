#include <string>
#include <vector>

using namespace std;

bool IsComposite(const int n)
{
    bool result = false;
    if(n < 2)
    {
        result = true;        
    }
    else
    {
        for(int iter = 2; iter < n; ++iter)
        {
            if(n % iter == 0)
            {
                result = true;
            }
        }
    }
    
    return result;
}


int solution(int n) {
    int answer = 0;
    
    for(int iter = 2; iter <= n; ++iter)
    {
        if(IsComposite(iter))
        {
            ++answer;
        }
    }
    
    return answer;
}