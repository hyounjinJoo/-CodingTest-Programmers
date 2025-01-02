#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string Subak = "수박";
    for(int i = 0; i < n / 2; ++i)
    {
        answer += Subak;
    }
    
    if(n % 2 != 0)
    {
        answer += "수";
    }
    
    return answer;
}