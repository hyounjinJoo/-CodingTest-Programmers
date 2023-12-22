#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    int count = static_cast<int>(array.size());
    for(int index = 0; index < count; ++index)
    {
        if(n == array[index])
        {
            ++answer;
        }
    }
    
    return answer;
}