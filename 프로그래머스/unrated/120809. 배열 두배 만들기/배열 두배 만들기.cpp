#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    size_t numCount = numbers.size();
    for(size_t index = 0; index < numCount; ++index)
    {
        numbers[index] *= 2;
    }
    
    return numbers;
}