#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s) {
    long long answer = 0;
    vector<string> numbers = 
    {
        "zero","one","two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    
    int length = s.length();
    string Temp;
    for(int IDX = 0; IDX < length; ++IDX)
    {
        if(isdigit(s[IDX]))
        {
            Temp += s[IDX];
            continue;
        }
        
        // numbers의 0부터 비교
        for(int NumIDX = 0; NumIDX < 10; ++NumIDX)
        {
            if(numbers[NumIDX] == s.substr(IDX, numbers[NumIDX].length()))
            {
                Temp += to_string(NumIDX);
            }
        }
    }
    
    answer = stoll(Temp);
    
    return answer;
}