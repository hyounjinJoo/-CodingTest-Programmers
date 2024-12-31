#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s.length() % 2 == 0)
    {
        size_t IDX = s.length() / 2 - 1;
        answer.push_back(s.at(IDX));
        answer.push_back(s.at(IDX + 1));
    }
    else
    {
        size_t IDX = s.length() / 2;
        answer.push_back(s.at(IDX));
    }
    
    return answer;
}