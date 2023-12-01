#include <string>
#include <vector>
#include <cmath>

using namespace std;

inline float CalcDiscountRatio(int price)
{
    int quotient = price / 100000;
    
    float ratio = 0.f;
    if(quotient >= 5)
    {
        ratio = 0.2f;
    }
    else if(quotient >= 3)
    {
        ratio = 0.1f;
    }
    else if(quotient >= 1)
    {
        ratio = 0.05f;
    }
        
    return ratio;
}

int solution(int price) {
    // 할인가격 결정
    float discount = CalcDiscountRatio(price) * price;
    //discount = floor(discount);
    
    //int answer = price - static_cast<int>(discount);
    int answer = static_cast<float>(price) - discount;
    
    
    return answer;
}