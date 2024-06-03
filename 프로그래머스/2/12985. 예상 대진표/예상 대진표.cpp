#include <vector>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    // 벡터에 승자만 넣고
    // 해당 벡터의 크기는 1/2로 작아질 것임
    // 벡터가 줄어든 횟수가 answer의 증가로 이어짐
    // 벡터는 Idx, Idx+1의 원소끼리 만나게 됨
    // Idx == a 이거나 Idx == b일 때, Idx + 1이 b이거나 a이면 반복 탈출
    // 아니면
    vector<int> Participant;
    for(int NumberIdx = 0; NumberIdx < n; ++NumberIdx)
    {
        Participant.push_back(NumberIdx + 1);
    }
    
    vector<int> ResultParticipant;
    bool bNeedContinue = true;
    int CountPlayer = Participant.size();
    while(bNeedContinue)
    {
        for(int Idx = 0; Idx < CountPlayer; Idx += 2)
        {
            int LPlayer = Participant[Idx];
            int RPlayer = Participant[Idx + 1];
            
            if((LPlayer == a && RPlayer == b) || (LPlayer == b && RPlayer == a))
            {                
                bNeedContinue = false;
                break;
            }
            else
            {                
                // a일 때는 a만 넣고
                // b일 때는 b만 넣고
                // 둘 다 아닐 때는 RPlayer만 살리자
                if(LPlayer == a || LPlayer == b)
                {
                    ResultParticipant.push_back(LPlayer);     
                }
                else
                {
                    ResultParticipant.push_back(RPlayer);
                }
                
            }            
        }
        Participant = ResultParticipant;
        CountPlayer = Participant.size();
        ResultParticipant.clear();
        ++answer;
    }

    return answer;
}