#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    for(size_t IDX = 0; IDX < phone_number.size() - 4; ++IDX)
    {
        answer[IDX] = '*';
    }
    
    return answer;
}