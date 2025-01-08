#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> triVector;
    while(n > 0)
    {
        triVector.push_back(n % 3);
        n /= 3;
    }
    
    int powNumber = 1;
    
    while(!triVector.empty()) 
    {
        answer += powNumber * triVector.back();
        triVector.pop_back();
        powNumber *=3;
    }

    return answer;
}