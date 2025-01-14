#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    size_t Size = numbers.size();
    vector<int> Test(numbers.size(), 0);
    Test[Size - 2] = Test[Size - 1] = 1;    

    set<int> uniqueNumbers;
    do 
    {
        int Result = 0;
        for (int IDX = 0; IDX < Test.size(); ++IDX)
        {
            if (Test[IDX] == 1)
            {
                Result += numbers[IDX];
            }
        }

        uniqueNumbers.insert(Result);
    } while (next_permutation(Test.begin(), Test.end()));
    
    vector<int> answer;
    for(auto Number : uniqueNumbers)
    {
        answer.push_back(Number);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}