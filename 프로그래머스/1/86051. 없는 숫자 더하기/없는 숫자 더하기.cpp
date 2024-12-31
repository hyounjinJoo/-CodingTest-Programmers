#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(size_t IDX = 0; IDX < numbers.size(); ++IDX)
    {
        answer -= numbers[IDX];
    }
    
    return answer;
}