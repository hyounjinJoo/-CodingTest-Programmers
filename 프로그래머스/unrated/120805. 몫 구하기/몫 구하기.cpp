#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) 
{
    const float num1Float = static_cast<float>(num1);
    const float num2Float = static_cast<float>(num2);
    
    return static_cast<int>(num1Float / num2Float);
}