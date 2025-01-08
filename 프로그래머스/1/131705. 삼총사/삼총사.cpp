#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    size_t NumberCount = number.size();
    
    vector<int> forPermute(NumberCount);
    fill(forPermute.begin(), forPermute.end(), 1);
    forPermute[0] = 0;
    forPermute[1] = 0;
    forPermute[2] = 0;
    
    do
    {
        int Sum = 0;
        for(size_t IDX = 0; IDX < NumberCount; ++IDX)
        {
            if(forPermute[IDX] == 0)
            {
                Sum += number[IDX];
            }
        }
        
        if(Sum == 0)
        {
            ++answer;
        }        
    }while(next_permutation(forPermute.begin(), forPermute.end()));
    
    return answer;
}