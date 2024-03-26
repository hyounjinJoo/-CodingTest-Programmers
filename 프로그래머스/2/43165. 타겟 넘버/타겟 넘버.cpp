#include <string>
#include <vector>

using namespace std;

void RecursiveDFS(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0)
{
    int SizeOfNumbers = numbers.size() - 1;
    if(count == SizeOfNumbers)
    {
        if(target == sum + numbers[count])
        {
            ++answer;
        }
        if(target == sum - numbers[count])
        {
            ++answer;
        }
        
        return;
    }
    
    RecursiveDFS(numbers, answer, target, count + 1, sum + numbers[count]);
    RecursiveDFS(numbers, answer, target, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    
    RecursiveDFS(numbers, answer, target);
    
    return answer;
}