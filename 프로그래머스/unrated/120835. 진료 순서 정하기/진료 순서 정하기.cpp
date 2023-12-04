#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> temp = emergency;
    sort(temp.begin(), temp.end(), greater<int>());
    
    size_t emergencySize = emergency.size();
    for(int iterEmer = 0; iterEmer < emergencySize; ++iterEmer)
    {
        for(int iterTemp = 0; iterTemp < emergencySize; ++iterTemp)
        {
            if(emergency[iterEmer] == temp[iterTemp])
            {
                answer.push_back(iterTemp + 1);
                break;
            }
        }
    }
    
    return answer;
}