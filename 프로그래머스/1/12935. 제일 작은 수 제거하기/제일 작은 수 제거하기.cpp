#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool compare(int left, int right)
{
    return left >= right;
}

vector<int> solution(vector<int> arr) 
{
    vector<int> answer = arr;
    
    int SmallestIDX = 0;
    int SmallestValue = std::numeric_limits<int>::max();
    for(int IDX = 0; IDX < answer.size(); ++IDX)
    {
        if(SmallestValue >= answer[IDX])
        {
            SmallestValue = answer[IDX];
            SmallestIDX = IDX;
        }
    }
    
    answer.erase(answer.begin() + SmallestIDX);
    
    if(0 == answer.size())
    {
        answer.push_back(-1);
    }
    
    return answer;
}