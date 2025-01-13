#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // 임시로 사용할 숫자들을 담아놓을 것
    vector<int> Temp;
    for (int ComIDX = 0; ComIDX < commands.size(); ++ComIDX)
    {
        Temp.clear();
        // 숫자를 command에 따라 담는다.
        for(int IDX = commands[ComIDX][0]; IDX <= commands[ComIDX][1]; ++IDX)
        {
            Temp.push_back(array[IDX - 1]);
        }
        // 담아놓은 숫자의 정렬
        sort(Temp.begin(), Temp.end());
        // 담아놓은 숫자 중 k번째의 것 추출 // answer에 추출한 숫자를 넣는다.
        answer.push_back(Temp[commands[ComIDX][2] - 1]);
    }

    return answer;
}