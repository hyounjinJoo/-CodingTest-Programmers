#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    size_t ScoreCount = score.size();
    for(size_t IDX = m - 1; IDX < ScoreCount; IDX += m)
    {
        answer += m * score[IDX];
    }
    
    return answer;
}