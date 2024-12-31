#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(size_t IDX = 0; IDX < absolutes.size(); ++IDX)
    {
        answer += signs[IDX] ? absolutes[IDX] : -absolutes[IDX];
    }
    
    return answer;
}