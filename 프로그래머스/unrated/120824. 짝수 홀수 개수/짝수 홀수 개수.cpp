#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    // 정수 리스트 : num_list
    // 짝수개수 세서 배열에 넣기
    // 홀수개수 세서 배열에 넣기
    vector<int> answer;
    size_t numCount = num_list.size();
    
    size_t num2X = 0;
    for(size_t index = 0; index < numCount; ++index)
    {
        if(0 == (num_list[index] % 2))
        {
            ++num2X;
        }
    }
    
    answer.push_back(static_cast<int>(num2X));
    answer.push_back(static_cast<int>(numCount - num2X));
    
    return answer;
}