#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    
    int strCount = static_cast<int>(strlist.size());
    int eachStrLength = 0;
    for(int index = 0; index < strCount; ++index)
    {
        eachStrLength = static_cast<int>(strlist[index].size());
        answer.push_back(eachStrLength);
    }
    
    return answer;
}