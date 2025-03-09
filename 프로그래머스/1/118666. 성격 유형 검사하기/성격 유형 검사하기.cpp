#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    // 각 유형에 따라 점수가 있다.
    // 따라서 맵으로 관리하는게 낫지 않을까?
    map<char, int> ScorePerTypeMap;
    for(int Index = 0; Index < choices.size(); ++Index)
    {
        if(choices[Index] == 4)
        {
            continue;
        }
        
        // 원소는 1~7이다.
        // 4를 기준으로 -인 경우 3, 2, 1
        // +인 경우 1, 2, 3
        if(choices[Index] < 4)
        {
            ScorePerTypeMap[survey[Index][0]] += (4 - choices[Index]);
        }
        else
        {
            ScorePerTypeMap[survey[Index][1]] += (choices[Index] - 4);
        }
    }

    string answer = "";

    // 각 지표별로 값 비교
    if(ScorePerTypeMap['R'] >= ScorePerTypeMap['T'])
    {
        answer.push_back('R');
    }
    else
    {
        answer.push_back('T');
    }
    
    if(ScorePerTypeMap['C'] >= ScorePerTypeMap['F'])
    {
        answer.push_back('C');
    }
    else
    {
        answer.push_back('F');
    }
    
    if(ScorePerTypeMap['J'] >= ScorePerTypeMap['M'])
    {
        answer.push_back('J');
    }
    else
    {
        answer.push_back('M');
    }
    
    if(ScorePerTypeMap['A'] >= ScorePerTypeMap['N'])
    {
        answer.push_back('A');
    }
    else
    {
        answer.push_back('N');
    }
    
    
    return answer;
}