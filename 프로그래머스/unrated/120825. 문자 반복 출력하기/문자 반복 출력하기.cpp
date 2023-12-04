#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    // my_string에 들어있는 각 문자를 n 만큼 반복한 문자열
    
    string answer = "";
    size_t charCount = my_string.size();
    for(size_t index = 0; index < charCount; ++index)
    {
        for(int iter = 0; iter < n; ++iter)
        {            
            answer.push_back(my_string[index]);
        }
    }
    
    return answer;
}