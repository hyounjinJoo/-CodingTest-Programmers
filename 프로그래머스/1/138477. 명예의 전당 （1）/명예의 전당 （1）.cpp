#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int Left, int Right)
{
    return Left >= Right;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> HallOfFame;
    
    size_t Limit = score.size();
    for(size_t IDX = 0; IDX < Limit; ++IDX)
    {
        //0. 초기에 k일까지는 모든 출연 가수의 점수가 명예의 전당에 오르게
        if(IDX <= (k - 1))
        {
            HallOfFame.push_back(score[IDX]);
        }
        else
        {
            //1. k번째 순위의 가수 점수보다 더 높으면 
            //1-1. 출연 가수의 점수가 명예의 전당에 오르게 되고
            //1-2. 기존의 k번째 순위의 점수는 명예의 전당에서 내려오게 됩니다.
            if(score[IDX] > HallOfFame[k - 1])
            {
                HallOfFame.insert(HallOfFame.begin() + (k - 1), score[IDX]);
                HallOfFame.erase(HallOfFame.begin() + k);                
            }
        }
        
        // 명예의 전당 정렬
        sort(HallOfFame.begin(), HallOfFame.end(), Compare);
        // 꼴찌를 answer에 기록
        answer.push_back(HallOfFame.back());
    }    
    
    return answer;
}