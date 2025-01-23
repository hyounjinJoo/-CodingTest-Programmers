#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    // 페인트가 칠해진 길이가 n미터인 벽
    // 학교는 벽에 페인트를 덧칠하기로
    // 구역을 나누어 일부만 페인트를 새로 칠
    // 벽을 1미터 길이의 구역 n개로 나누고
    // 각 구역에 왼쪽부터 순서대로 1번부터 n번까지 번호
    // 페인트를 다시 칠해야 할 구역들을 정했습니다.
    // 벽에 페인트를 칠하는 롤러의 길이는 m미터
    // 롤러로 벽에 페인트를 한 번 칠하는 규칙
    // 1. 롤러가 벽에서 벗어나면 안 됩니다.
    // 2. 구역의 일부분만 포함되도록 칠하면 안 됩니다.
    // 3. 한 구역에 페인트를 여러 번 칠해도 되고 다시 칠해야 할 구역이 아닌 곳에 페인트를 칠해도 되지만
    //    다시 칠하기로 정한 구역은 적어도 한 번 페인트칠을 해야함.
    // 롤러로 페인트칠해야 하는 최소 횟수 return
    // 정수 n, m과 다시 페인트를 칠하기로 정한 구역들의 번호가 담긴 정수 배열 section이 매개변수
    
    // 벽은 1~n번까지의 번호를 지닌다.
    vector<bool> Wall(n);
    fill(Wall.begin(), Wall.end(), true);
    for(int Number : section)
    {
        // 칠해야 할 벽을 false로 바꿔준다.
        Wall[Number - 1] = false;        
    }
    
    for(int IDX = 0; IDX < Wall.size(); ++IDX)
    {
        if(Wall[IDX])
        {
           continue; 
        }
        
        for(int Target = IDX; Target < (IDX + m) && Target < Wall.size(); ++Target)
        {
            Wall[Target] = true;
        }
        ++answer;
    }
    
    return answer;
}