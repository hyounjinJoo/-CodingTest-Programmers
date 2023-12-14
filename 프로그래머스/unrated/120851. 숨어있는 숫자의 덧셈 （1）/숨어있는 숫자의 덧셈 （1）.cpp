#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    int num0 = '0';
    int num9 = '9';
    
    int length = static_cast<int>(my_string.size());
        
    for(int index = 0; index < length; ++index)
    {
        if(num0 <= my_string[index] && my_string[index] <= num9)
        {
            answer +=  (my_string[index] - num0);
        }
    }    
    
    return answer;
}