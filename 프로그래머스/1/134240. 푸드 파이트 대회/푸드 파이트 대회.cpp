#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int insertCount = 0;
    for(int IDX = 1; IDX < food.size(); ++IDX)
    {
        // 해당 인덱스의 food가 2개 이상이면 앞 뒤로 넣을 수 있다.
        while(food[IDX] / 2 > 0)
        {
            answer.insert(insertCount, to_string(IDX));
            answer.insert(answer.length() - insertCount, to_string(IDX));
            ++insertCount;
            food[IDX] -= 2;
        }
    }
    
    answer.insert(answer.length() / 2, to_string(0));
    
    return answer;
}