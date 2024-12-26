#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    set<int> Test;
    for(int Number : arr)
    {
        if(Number % divisor == 0)
        {
            Test.insert(Number);
        }
    }
    
    vector<int> answer;
    for(int Number : Test)
    {
        answer.push_back(Number);
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
    }
    
    return answer;
}