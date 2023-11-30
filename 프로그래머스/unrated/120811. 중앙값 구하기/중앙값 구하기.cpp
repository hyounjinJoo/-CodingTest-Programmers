#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    std::sort(array.begin(), array.end());
    size_t arraySize = array.size();
    size_t middlePos = static_cast<size_t>(arraySize / 2);
    answer = array[middlePos];
    
    return answer;
}