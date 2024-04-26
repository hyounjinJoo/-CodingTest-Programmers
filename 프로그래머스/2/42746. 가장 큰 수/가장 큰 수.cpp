#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int left, int right)
{
    std::string leftStr = to_string(left);
    std::string rightStr = to_string(right);
    
    // 610 ... 106
    // 62 ... 26
    // 102 ... 210
    // 6 ... 2 ... 10    
	return leftStr + rightStr > rightStr + leftStr;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    
    for(int number : numbers)
    {
        answer += to_string(number);
    }
    
    if('0' == answer[0])
    {
        answer = "0";
    }
    
    return answer;
}