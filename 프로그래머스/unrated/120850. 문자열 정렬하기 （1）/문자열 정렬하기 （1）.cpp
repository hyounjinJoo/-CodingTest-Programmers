#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    int num0 = '0';
    int num9 = '9';
    
    int length = my_string.size();
    for(int index = 0; index < length; ++index)
    {
        if(num0 <= my_string[index] && my_string[index] <= num9)
        {
            answer.push_back(my_string[index] - num0);
        }
    }
    
    std::sort(answer.begin(), answer.end());
    
    return answer;
}