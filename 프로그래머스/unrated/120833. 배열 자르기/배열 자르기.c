#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len, int num1, int num2) {
    /*
    numbers             num1    num2    result
    [1, 2, 3, 4, 5]	    1	    3	    [2, 3, 4]
    [1, 3, 5]	        1	    2	    [3, 5]
    */
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t resultCount = num2 - num1 + 1;
    int* answer = (int*)malloc((resultCount + 1) * sizeof(int));
    
    for(int index = 0; index < resultCount; ++index)
    {
        *(answer + index) = *(numbers + (num1 + index));
    }
    
    return answer;
}