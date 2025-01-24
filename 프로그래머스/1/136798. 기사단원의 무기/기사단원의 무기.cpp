#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;
    // 각 기사 1번부터 number까지 번호가 지정
    // 기사들은 무기점에서 무기를 구매
    // 각 기사는 자신의 기사 번호의 약수 개수에 해당하는 공격력을 가진 무기를 구매
    // 이웃나라와의 협약에 의해 공격력의 제한수치를 정하고, 제한수치보다 큰 공격력을 가진 무기를 구매해야 하는 기사는 협약기관에서 정한 공격력을 가지는 무기를 구매
    // 15번으로 지정된 기사단원은 15의 약수가 1, 3, 5, 15로 4개 이므로, 공격력이 4인 무기를 구매
    // 만약, 이웃나라와의 협약으로 정해진 공격력의 제한수치가 3이고 제한수치를 초과한 기사가 사용할 무기의 공격력이 2라면, 15번으로 지정된 기사단원은 무기점에서 공격력이 2인 무기를 구매
    // 무기를 만들 때, 무기의 공격력 1당 1kg의 철이 필요, 무기점에서 무기를 모두 만들기 위해 필요한 철의 무게를 미리 계산
    
    // 1부터 number까지 각각 숫자의 약수를 구한다.
    // 약수의 갯수가 limit을 넘어가는 경우 power를 answer에 더하고
    // 아닌 경우 약수의 갯수를 answer에 더한다.
    // 약수의 갯수는 1부터 해당 숫자까지 나누어서 나머지가 0인 수이다.
    // number가 100,000이므로 O(N^2)까지 괜찮다 생각했으나 시간초과가 발생한다.
    
    int Attack = 1;
    int MaxVerify = 0;
    for(int Knight = 2; Knight <= number; ++Knight)
    {
        Attack = 0;
        MaxVerify = sqrt(Knight);
        
        for(int Test = 1; Test <= MaxVerify; ++Test)
        {
            if(Knight % Test == 0)
            {
                if(Knight / Test == Test) ++Attack;
                else Attack += 2;
            }
        }
        
        if(Attack > limit) answer += power;
        else answer += Attack;
    }    
    
    return answer;
}