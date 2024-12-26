#include <string>
#include <vector>

using namespace std;

#define Left 0
#define Right 1
#define Top 2
#define Down 3

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer(n, vector<int>(n, 0));

    int CountOfNSquare = n * n;
    int PosX = 0, PosY = 0;
    int NextMoveDir = Right;
    bool bChangeDir = false;

    for (int IDX = 0; IDX < CountOfNSquare; ++IDX)
    {
        // 현재 위치에 값 저장
        answer[PosY][PosX] = IDX + 1;
        // 다음 이동 방향 판별
        switch(NextMoveDir)
        {
        case Right:
            // 배열 범위를 벗어나지 않을 경우
            // 이미 값이 설정된 경우
            if(PosX + 1 < n && answer[PosY][PosX + 1] == 0)
            {
                ++PosX;
            }
            else
            {
                NextMoveDir = Down;
                bChangeDir = true;
            }
            break;
        case Down:
            // 배열 범위를 벗어나지 않을 경우
            // 이미 값이 설정된 경우
            if (PosY + 1 < n && answer[PosY + 1][PosX] == 0)
            {
                ++PosY;
            }
            else
            {
                NextMoveDir = Left;
                bChangeDir = true;
            }
            break;
        case Left:
            // 배열 범위를 벗어나지 않을 경우
            // 이미 값이 설정된 경우
            if (PosX - 1 >= 0 && answer[PosY][PosX - 1] == 0)
            {
                --PosX;
            }
            else
            {
                NextMoveDir = Top;
                bChangeDir = true;
            }
            break;
        case Top:
            // 배열 범위를 벗어나지 않을 경우
            // 이미 값이 설정된 경우
            if (PosY - 1 >= 0 && answer[PosY - 1][PosX] == 0)
            {
                --PosY;
            }
            else
            {
                NextMoveDir = Right;
                bChangeDir = true;
            }
            break;
        default:
            break;
        }

        if(bChangeDir)
        {
            bChangeDir = false;
            switch(NextMoveDir)
            {
            case Down:
                ++PosY;
                break;
            case Left:
                --PosX;
                break;
            case Top:
                --PosY;
                break;
            case Right:
                ++PosX;
                break;
            }
        } 
    } 

    return answer;
}
