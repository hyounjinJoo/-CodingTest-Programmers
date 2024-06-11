#include <vector>

using namespace std;

vector<int> solution(vector<int> Prices) 
{
    vector<int> Answer;
    int Size = Prices.size();
    
    for(int OutIdx = 0; OutIdx < Size; ++OutIdx)
    {
        int Time = 0;
        for(int InIdx = OutIdx + 1; InIdx < Size; ++InIdx)
        {
            ++Time;
            if(Prices[OutIdx] > Prices[InIdx])
            {
                break;
            }            
        }
        
        Answer.push_back(Time);
    }
    
    return Answer;
}