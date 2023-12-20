#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    // z - 0    | +4    
    // o - 1    | +3
    
    // t - 2    | +3
    // t - 3    | +5

    // f - 4    | +4
    // f - 5    | +4

    // s - 6    | +3
    // s - 7    | +5
    
    // e - 8    | +5    
    // n - 9    | +4
    
    long long answer = 0;
    
    int length = static_cast<int>(numbers.size());
    for(int index = 0; index < length;)
    {
        answer *= 10;
        
        if('z' == numbers[index])
        {
            index += 4;
        }
        else if('o' == numbers[index])
        {
            answer += 1;
            index += 3;
        }
        else if('e' == numbers[index])
        {
            answer += 8;
            index += 5;
            
        }
        else if('n' == numbers[index])
        {
            answer += 9;
            index += 4;
        }
        else
        {
            if('t' == numbers[index])
            {
                if('w' == numbers[index+1])
                {
                    answer += 2;
                    index += 3;
                }
                else
                {                    
                    answer += 3;
                    index += 5;
                }
            }
            else if('f' == numbers[index])
            {
                if('o' == numbers[index+1])
                {
                    answer += 4;
                }
                else
                {                    
                    answer += 5;
                }
                index += 4;
            }
            else
            {
                if('i' == numbers[index+1])
                {
                    answer += 6;
                    index += 3;
                }
                else
                {                    
                    answer += 7;
                    index += 5;
                }
            }            
        }
    }
    
    return answer;
}