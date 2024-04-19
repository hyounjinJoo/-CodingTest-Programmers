#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int WholeTile = brown + yellow;
    // yellow => (width - 2) * (height - 2)
    // brown => WholeTile - yellow
    int Width = WholeTile;
    int Height = 0;
    int TempYellow = 0;
    int TempBrown = 0;
    for(; Width > 0; --Width)
    {
        if(WholeTile % Width)
        {
            continue;
        }
        
        Height = WholeTile / Width;
        TempYellow = (Width - 2) * (Height - 2);
        TempBrown = WholeTile - TempYellow;
        if(yellow == TempYellow && brown == TempBrown)
        {
            break;
        }
    }
    
    answer.push_back(Width);
    answer.push_back(Height);
    return answer;
}