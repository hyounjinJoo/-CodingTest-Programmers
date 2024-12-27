#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    // 배열의 길이와 정수 크기를 보았을 때, 최악의 경우 10000 * 100 이므로 
    // O(n)으로 처리해도 무방
    for(int Number : arr)
    {
        answer += Number;
    }
    
    // 마찬가지로 int로 size()를 캐스팅해도 무방
    answer /= static_cast<int>(arr.size());
    
    return answer;
}