#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    // wallpaper의 원소 중 빈칸은 .  파일이 있으면 # 
    
    vector<int> answer;
    // + 형태인 경우 시작점은 가장 작은 luy와 가장 작은 lux가 좌표인 점을 구해야 하므로 이를 기준으로 삼아보자
    // 끝점은 반대로 가장 큰 rdx, 가장 큰 rdy를 구해야 한다.
    
    int MinPosY = 50;
    int MinPosX = 50;

    int MaxPosY = -1;
    int MaxPosX = -1;    
    for(int PosY = 0; PosY < wallpaper.size(); ++PosY)
    {
        for(int PosX = 0; PosX < wallpaper[0].size(); ++PosX)
        {
            if(wallpaper[PosY][PosX] == '#')
            {
                if(MinPosY > PosY)
                {
                    MinPosY = PosY;
                }
                
                if(MinPosX > PosX)
                {
                    MinPosX = PosX;
                }
                
                if(MaxPosY <= PosY)
                {
                    MaxPosY = PosY+1;
                }
                
                if(MaxPosX <= PosX)
                {
                    MaxPosX = PosX+1;
                }
            }
        }
    }
    
    answer.push_back(MinPosY);
    answer.push_back(MinPosX);
    answer.push_back(MaxPosY);
    answer.push_back(MaxPosX);
    
    return answer;
}