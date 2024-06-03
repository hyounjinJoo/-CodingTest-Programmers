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
        
    vector<int> Participant;
    // 1. 선수 등록
    for(int NumberIdx = 0; NumberIdx < n; ++NumberIdx)
    {
        Participant.push_back(NumberIdx + 1);
    }
    
    vector<int> RoundResult;
    bool bNeedContinue = true;
    int CountPlayer = Participant.size();
    // 2. 경기 진행, 라이벌을 만나기 전까지. 이 반복은 각 라운드를 의미한다.
    while(bNeedContinue)
    {
        // 3. 각 라운드 내의 매치
        for(int Idx = 0; Idx < CountPlayer; Idx += 2)
        {
            // 홍코너 참가자
            int LPlayer = Participant[Idx];
            // 청코너 참가자
            int RPlayer = Participant[Idx + 1];
            
            // 라이벌을 만났다.
            if((LPlayer == a && RPlayer == b) || (LPlayer == b && RPlayer == a))
            {                
                bNeedContinue = false;
                break;
            }
            // 라이벌이 아닌 자를 만났다.
            else
            {                
                // a일 때는 a만 넣고
                // b일 때는 b만 넣고
                // 둘 다 아닐 때는 RPlayer만 살리자
                if(LPlayer == a || LPlayer == b)
                {
                    RoundResult.push_back(LPlayer);     
                }
                else
                {
                    RoundResult.push_back(RPlayer);
                }
                
            }            
        }
        
        // 이 라운드의 모든 매치가 종료되었다.
        Participant = RoundResult;
        CountPlayer = Participant.size();
        RoundResult.clear();
        ++answer;
    }

    return answer;
}