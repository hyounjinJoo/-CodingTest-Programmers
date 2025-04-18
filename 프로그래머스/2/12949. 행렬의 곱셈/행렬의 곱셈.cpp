#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int Row = arr1.size(), Col = arr2[0].size();
    
    vector<vector<int>> answer(Row, vector<int>(Col, 0));
    
    
    for (int i=0; i<Row; i++) {
        for (int j=0; j<Col; j++) {
            for (int k=0; k<arr1[0].size(); k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}