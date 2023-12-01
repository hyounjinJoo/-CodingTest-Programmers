#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    size_t numberCount = numbers.size();
    double answer = 0;
    
    for(size_t index = 0; index < numberCount; ++index)
    {
        answer += numbers[index];
    }
    
    answer /= static_cast<double>(numberCount);
    
    return answer;
}