#include <iostream>
using namespace std;

int solution(int Number)
{        
    return __builtin_popcount(Number);
}

//int solution(int Number)
//{
//    int Answer = 0;
//    
//    while(Number)
//    {
//        Number &= (Number - 1);
//        ++Answer;
//    }
//    
//    return Answer;
//}
