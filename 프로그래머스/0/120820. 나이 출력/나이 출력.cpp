#include <string>
#include <vector>

using namespace std;

#define YEAR 2022
int solution(int age) {
    // 2022년 기준 출생연도를 return한다.
    // 2022 - 40 = 1983...? 1982 + 1
    
    int answer = YEAR - age + 1;
    return answer;
}