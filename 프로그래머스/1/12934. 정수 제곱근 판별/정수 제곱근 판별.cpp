long long solution(long long n) {
    long long answer = 0;
    
    // 제곱 판단 : n을 x로 나누었을 때, 몫이 x가 나오는 숫자를 찾는다.
    // 찾아지는지 아닌지가 나뉜다.
    bool bFind = false;
    // 양의 정수이므로 어떤 수는 최소 1.0부터 시작하게 된다. 양수가 제곱이 되는 경우는 1.0부터 이므로
    for(double Number = 1.f; Number <= n; Number += 1.f)
    {
        if(n / Number == Number)
        {
            bFind = true;
            answer = static_cast<long long>((Number + 1.f) * (Number + 1.f));
            break;
        }
    }
    
    if(false == bFind)
    {
        answer = -1;
    }
    
    return answer;
}