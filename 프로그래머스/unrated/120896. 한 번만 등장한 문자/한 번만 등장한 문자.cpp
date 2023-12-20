#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int length = s.size();
    std::vector<int> countAlphabet;
    int totalLowerAlphabetCount = static_cast<int>('z' - 'a');
    countAlphabet.resize(totalLowerAlphabetCount);
        
    string answer = "";
    
    const char aASCVal = 'a';
    for(int index = 0; index < length; ++index)
    {
        countAlphabet[s[index] - aASCVal]++;
    }
    
    length = totalLowerAlphabetCount + 1;
    for(int index = 0; index < length; ++index)
    {
        if(1 == countAlphabet[index])
        {
            answer.push_back(index + aASCVal);
        }
    }
    
    return answer;
}