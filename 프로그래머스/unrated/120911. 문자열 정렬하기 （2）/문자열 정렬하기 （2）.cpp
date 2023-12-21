#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    size_t length = my_string.size();
    std::vector<char> temp;
    for(size_t index = 0; index < length; ++index)
    {
        if(my_string[index] <= 'Z')
        {
            my_string[index] += ('a' - 'A');
        }
        
        temp.push_back(my_string[index]);
    }
    std::sort(temp.begin(), temp.end());
    
    for(size_t index = 0; index < length; ++index)
    {
        answer.push_back(temp[index]);
    }
    
    return answer;
}