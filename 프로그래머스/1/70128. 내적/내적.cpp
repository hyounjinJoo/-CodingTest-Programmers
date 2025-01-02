#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for(int Index = 0; Index < a.size(); ++Index)
    {
        answer += a[Index] * b[Index];
    }
    
    return answer;
}