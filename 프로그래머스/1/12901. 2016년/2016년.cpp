#include <string>
#include <vector>

using namespace std;

// 1월 1일은 금요일
// 1 : 31
// 2 : 29
// 3 : 31
// 4 : 30
// 5 : 31
// 6 : 30
// 7 : 31
// 8 : 31
// 9 : 30
// 10: 31
// 11: 30
// 12: 31
// 금 : 0
// 토 : 1
// 일 : 2
// 월 : 3
// 화 : 4
// 수 : 5
// 목 : 6
string solution(int a, int b) {
    string answer = "";
    vector<string> Day = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    vector<int> DayPerMonth;
    {
        int Day = 0;
        for(int Month = 1; Month < 13; ++Month)
        {
            if(Month < 8)
            {
                 Day = Month % 2 == 1 ? 31 : 30;
            }
            else
            {
                Day = Month % 2 == 0 ? 31 : 30;
            }
            
            if(Month == 2)
            {
                Day = 29;
            }
            
            DayPerMonth.push_back(Day);
        }
    }
        
    b--;
    for(int Iter = 1; Iter < a; ++Iter)
    {
        b += DayPerMonth[Iter-1];
    }
    
    b = b % 7;
    
    answer = Day[b];
    
    return answer;
}