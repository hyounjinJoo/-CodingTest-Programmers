using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    //원래 이용료는 price원 인데, 놀이기구를 N 번 째 이용한다면 원래 이용료의 N배
    //놀이기구를 count번 타게 되면 현재 자신이 가지고 있는 금액에서 얼마가 모자라는지를 return
    //단, 금액이 부족하지 않으면 0을 return
    
    for(int iter = 1; iter <= count; ++iter)
    {
        answer += iter * price;
    }
    
    if(money - answer >= 0)
    {
        answer = 0;
    }
    else
    {
        answer -= money;
    }
    
    return answer;
}