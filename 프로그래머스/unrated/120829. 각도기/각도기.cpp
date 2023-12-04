#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    
    int answer = 0;
    // 예각(1) : 0 < angle < 90
    // 직각(2) : angle = 90
    // 둔각(3) : 90 < angle < 180
    // 평각(4) : angle = 180
    if(0 < angle && angle < 90)
    {
        answer = 1;
    }
    else if(angle == 90)
    {
        answer = 2;
    }
    else if(90 < angle && angle < 180)
    {
        answer = 3;
    }
    else
    {
        answer = 4;
    }
    
    return answer;
}