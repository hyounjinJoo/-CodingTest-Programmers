int solution(int a, int b, int n) {
    int answer = 0;
    // 콜라 새 거 개수 n
    // 병 a개를 가져다 주면 새 거 b병을 준다.    
    int NewColar = 0;
    while(n >= a)
    {
        // 받을 수 있는 병의 개수 answer
        // 새로 받은 거는 다시 새 거에 추가된다.
        // 1. 받을 수 있는 개수를 미리 구한다.
        // 2. 새로 받은 것을 기록한다.(몫)
        // 3. answer에 더해준다.
        // 4. 전체 개수를 갱신한다. (2.의 나머지 + 몫)
        // 5. 다시 이를 n이 이상일 동안 반복한다.
        NewColar = n / a * b;
        answer += NewColar;
        n = (n % a) + NewColar;        
    }
        
    return answer;
}