#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> Players, vector<string> callings) {    
    // 이름과 현재 등수를 map에 기록
    int MaxSize = Players.size();
    map<string, int> PlayerMap;
    for(int IDX = 0; IDX < MaxSize; ++IDX)
    {
        PlayerMap[Players[IDX]] = IDX;
    }    
    
    for(const string& PlayerName : callings)
    {
        // 불렸을 때, map에 기록된 키의 값으로 인덱스를 찾아낸다.
        int RightIDX = PlayerMap[PlayerName];
        // players에서 해당 인덱스의 앞에 위치한 선수를 찾아낸다.
        int LeftIDX = RightIDX - 1;
        string LeftName = Players[LeftIDX];
        
        // players를 갱신하고
        Players[LeftIDX] = PlayerName;
        Players[RightIDX] = LeftName;
        // 두 선수의 map 상 값도 갱신한다.
        PlayerMap[PlayerName] = LeftIDX;
        PlayerMap[LeftName] = RightIDX;        
    }
    
    return Players;
}