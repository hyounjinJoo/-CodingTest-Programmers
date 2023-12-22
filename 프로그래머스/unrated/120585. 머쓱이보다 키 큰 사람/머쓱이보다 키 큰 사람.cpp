#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    int count = array.size();
    for(int index = 0; index < count; ++index)
    {
        if(array[index] > height)
        {
            ++answer;
        }
    }
    return answer;
}