#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int column;

bool compare(const vector<int>& a, const vector<int>& b)
{
    if(a[column] == b[column])
    {
        return a[0] > b[0];
    }
    else
    {
        return a[column] < b[column];
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;
    
    sort(data.begin(), data.end(), compare);
    
    for(int RowIDX = row_begin - 1; RowIDX < row_end; ++RowIDX)
    {
        int ModSum = 0;
        for(int IDX = 0; IDX < data[0].size(); ++IDX)
        {
            ModSum += (data[RowIDX][IDX] % (RowIDX + 1));
        }
        
        answer ^= ModSum;
    }
    
    return answer;
}