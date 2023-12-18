#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
	string answer = "";
	int length = static_cast<int>(my_string.size());
    int answerLength = 0;
	for (int index = 0; index < length; ++index)
	{
        bool isExist = false;
        for(int answerIndex = 0; answerIndex < answerLength; ++answerIndex)
        {
            if(my_string[index] == answer[answerIndex])
            {
                isExist = true;
                break;
            }
        }
        
        if(!isExist)
        {
            answer.push_back(my_string[index]);            
            ++answerLength;
        }
	}
    
    return answer;
}