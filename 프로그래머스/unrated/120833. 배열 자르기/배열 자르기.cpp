#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;
    
    size_t newSize = num2 - num1 + 1;
    for(size_t index = 0; index < newSize; ++index)
    {
        answer.push_back(numbers[num1 + index]);
    }
    
    return answer;
}