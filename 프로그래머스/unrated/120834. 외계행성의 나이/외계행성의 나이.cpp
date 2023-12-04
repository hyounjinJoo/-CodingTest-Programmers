#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    answer = to_string(age);
    
    size_t length = answer.length();
    for(size_t index = 0; index < length; ++index)
    {
       answer[index] += 49;
    }
    
    return answer;
}