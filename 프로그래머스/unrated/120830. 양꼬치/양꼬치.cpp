#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    // 10 인분, 음료수 하나 서비스
    // 양꼬치 1 : 12,000
    // 음료수 1 : 2,000
    
    int answer = 0;
    int shipCount = n;
    int drinkCount = k;
    
    drinkCount -= static_cast<int>( shipCount / 10);
    
    answer = shipCount * 12000 + drinkCount * 2000;
    
    return answer;
}