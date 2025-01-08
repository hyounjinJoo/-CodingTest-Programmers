#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tri;
    while(n > 0)
    {
        int number = n % 3;
        tri.push_back(n % 3);
        n /= 3;
        if(n == 1)
        {
            tri.push_back(1);
            break;
        }
    }
    for(int i = 0; i < tri.size(); i++)
    {
        answer += pow(3, tri.size() - i - 1) * tri[i];
    }
    
    return answer;
}