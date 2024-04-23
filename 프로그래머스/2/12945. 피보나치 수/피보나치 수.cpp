
int solution(int n) {
    int answer = 0;
    
    int left = 0;
    int right = 1;    
    int sum = 0;
    for(int F = 2; F <= n; ++F)
    {
        sum = (left + right) % 1234567;
        left = right;
        right = sum;
    }
    
    answer = sum;
    
    return answer;
}