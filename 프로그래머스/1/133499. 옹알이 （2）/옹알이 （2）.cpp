#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    // 발음할 수 있는 것은 아래의 4개만 가능
    vector<string> CanBabbling = {"aya", "ye", "woo", "ma"};

    int Answer = 0;
    // 네 가지 발음을 조합해서 하되, 연속으로 같은 발음은 할 수 없다.
    bool bIsCorrect = true;
    for(int BabblIDX = 0; BabblIDX < babbling.size(); ++BabblIDX)
    {        
        bIsCorrect = true;
        // 한 개씩 검사한다.
        int BeforeBabble = -1;
        for(int CHARIDX = 0; CHARIDX < babbling[BabblIDX].size();)
        {
            string Length3Word = babbling[BabblIDX].substr(CHARIDX, 3);
            string Length2Word = babbling[BabblIDX].substr(CHARIDX, 2);
            if(Length3Word == CanBabbling[0])
            {
                if(BeforeBabble == 0)
                {
                    bIsCorrect = false;
                    break;
                }
                BeforeBabble = 0;
                CHARIDX += 3;
            }
            else if(Length3Word == CanBabbling[2])
            {
                if(BeforeBabble == 2)
                {
                    bIsCorrect = false;
                    break;
                }
                BeforeBabble = 2;
                CHARIDX += 3;                
            }
            else if(Length2Word == CanBabbling[1])
            {
                if(BeforeBabble == 1)
                {
                    bIsCorrect = false;
                    break;
                }
                BeforeBabble = 1;
                CHARIDX += 2;                   
            }
            else if(Length2Word == CanBabbling[3])
            {
                if(BeforeBabble == 3)
                {
                    bIsCorrect = false;
                    break;
                }
                BeforeBabble = 3;
                CHARIDX += 2;                   
            }
            else
            {
                bIsCorrect = false;
                break;
            }
        }
            
        if(bIsCorrect)
        {
            ++Answer;
        }
    }
    
    return Answer;
}