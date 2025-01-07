#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer = arr1;
    
    int rowMax = answer.size();
    int columnMax = answer[0].size();
    
    for(int i = 0; i < rowMax; ++i)
    {
        for(int j = 0; j < columnMax; ++j)
        {
            answer[i][j] += arr2[i][j];
        }
    }
    
    return answer;
}