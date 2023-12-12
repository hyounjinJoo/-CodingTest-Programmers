#include <string>
#include <vector>

using namespace std;

struct Dot
{
    int posX;
    int posY;
    
    Dot() : posX(0), posY(0) {}
    Dot(const int x, const int y) : posX(x), posY(y) { }
        
    int FindPos()
    {
        int posXAxis = 0;
        if(posX > 0)
        {
            posXAxis = 1;
        }
        else if(posX < 0)
        {
            posXAxis = -1;
        }
        
        int posYAxis = 0;
        if(posY > 0)
        {
            posYAxis = 1;
        }
        else if(posY < 0)
        {
            posYAxis = -1;
        }
        
        int result = posXAxis + posYAxis;
        
        // 1 : 2
        // 2 : 0
        // 3 : -2
        // 4 : 0  
        switch(result)
        {
            case 0:
                if(posXAxis > 0)
                {
                    result = 4;
                }
                else
                {
                    result = 2;
                }
                break;
            case 2:
                result = 1;
                break;
            case -2:
                result = 3;
                break;                
            default:
                break;
        }
        
        return result;        
    }
};

int solution(vector<int> dot) {
    Dot point = Dot(dot[0], dot[1]);
    
    int answer = point.FindPos();
    
    return answer;
}