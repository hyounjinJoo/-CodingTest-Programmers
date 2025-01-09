#include <vector>
#include <limits>

using namespace std;

void swap(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}

constexpr size_t LEFT = 0;
constexpr size_t RIGHT = 1;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    size_t Size = sizes.size();
    int LeftMax = numeric_limits<int>::min();
    int RightMax = numeric_limits<int>::min();
    
    for(size_t IDX = 0; IDX < Size; ++IDX)
    {
        if(sizes[IDX][LEFT] > sizes[IDX][RIGHT])
        {
            swap(sizes[IDX][LEFT], sizes[IDX][RIGHT]);
        }
        
        if(LeftMax < sizes[IDX][LEFT])
        {
            LeftMax = sizes[IDX][LEFT];
        }
        
        if(RightMax < sizes[IDX][RIGHT])
        {
            RightMax = sizes[IDX][RIGHT];
        }
    }
    
    answer = LeftMax * RightMax;
    
    return answer;
}