#include <string>
#include <vector>

using namespace std;

// num_list 정수 배열
// n 정수
// 2차원 배열로 바꿔서 return
// n으로 나눈 길이로 바꿔서 2차원 배열을 만든다.

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    size_t numElements = num_list.size();
    size_t rowCount = numElements / n;
    
    std::vector<int> row;
    
    size_t currentRowIter = 0;
    // 0, 1
    // 2, 3
    // 4, 5
    // 6, 7
    for(size_t iter = 0; iter <= numElements; ++iter)
    {        
        if(0 == (iter % n) && (0 != iter))
        {
            answer.push_back(row);
            row.clear();            
        }
        row.push_back(num_list[iter]);
    }
    return answer;
}