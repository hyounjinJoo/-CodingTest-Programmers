#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int Pos = 0;
    for(size_t IDX = 0; IDX < seoul.size(); ++IDX)
    {
        if(seoul[IDX] == "Kim")
        {
           Pos = IDX;
           break;
        }
    }
    answer = "김서방은 " + to_string(Pos) + "에 있다";
    return answer;
}