int solution(int n) {
    int answer = 0;
    // 제한 사항을 고려하면 int를 사용해도 되며,
    // 입력값의 범위가 1,000,000가 최대이므로 O(n)으로 처리하되
    // n % x == 1이고 n이 3부터 시작이므로 x를 2부터 시작한다.
    // 최악의 경우는 x가 n - 1인 경우이다.
    // 최솟값을 찾는 것이므로, 해당 조건에 만족하면 반복문을 탈출한다.
    for(int Number = 2; Number < n; ++Number)
    {
        if(n % Number == 1)
        {
            answer = Number;
            break;
        }
    }
    
    return answer;
}