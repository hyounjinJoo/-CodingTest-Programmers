#include <string>
#include <vector>
#include <list>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int dir = 0;
    if(direction == ("right"))
    {
        dir = 1;
    }
    else
    {
        dir = -1;
    }
    
    size_t Size = numbers.size() - 1;
    
    list<int> movedList;
    // right
    if(1 == dir)
    {
        for(size_t index = 0; index < Size; ++index)
        {
            movedList.push_back(numbers[index]);
        }
        
        movedList.push_front(numbers[Size]);
    }
    else
    {
        for(size_t index = Size; index > 0; --index)
        {
            movedList.push_front(numbers[index]);
        }
        
        movedList.push_back(numbers[0]);
    }
    
    auto iter = movedList.begin();
    auto iterEnd = movedList.end();
        
    for(; iter != iterEnd; ++iter)
    {
    answer.push_back(*iter);
    }
    
    return answer;
}