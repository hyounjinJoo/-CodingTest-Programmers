#include <vector>
#include <algorithm>
using namespace std;

// 소수의 정의 : 1과 자기 자신으로만 나눌 수 있는 수
/*
bool IsPrime(int InNumber)
{
    // 1이면 소수가 아니므로 거짓이다.
    if(1 == InNumber)
        return false;
    
    bool Result = true;
    // 만약 2라면 자기 자신으로 나눌 수 있으므로 참이다.
    // 2부터 N까지 자기 자신 이전까지의 수로 나눌 수 있는지 순회로 검사한다.O(N)
    int Limit = InNumber - 1;
    for(int Number = 2; Number < Limit; ++Number)
    {
        if(InNumber % Number == 0)
        {
            Result = false;
            break;
        }
    }
    
    return Result;
}
*/

// 에라토스테네스의 체 사용
constexpr int MAX_SUM = 3001;
// 최대 3000이므로 1~3000까지라 가정하고 판별 
bool Primes[3001];

void IsPrime()
{
    fill(Primes, Primes + MAX_SUM, true);
    
    for(int Number = 2; Number < MAX_SUM; ++Number)
    {
        if(0 == Primes[Number])
            continue;
        
        for(int J = Number + Number; J <= MAX_SUM; J += Number)
            Primes[J] = false;
    }
}



int solution(vector<int> Nums) {
    int Answer = 0;
    // 주어진 숫자 중 "3개의 수를 더했을 때" 소수가 되는 경우의 개수
    // 제한사항 
    // 숫자의 개수는 3개 이상 50개 이하
    // 각 원소는 1 이상 1,000 이하
    
    // 조합을 사용하면 되는데 vector<bool>로 처리하는게 편리하므로 이를 사용하자
    vector<bool> Using;
    // 주어진 숫자들 - 3개만큼을 미리 만들어준다
    Using.resize(Nums.size() - 3);
    for(int Iter = 0; Iter < 3; ++Iter)
    {
        Using.push_back(true);
    }

    // 숫자 3개를 더한 임시값
    int Sum = 0;
    int UsingSize = static_cast<int>(Using.size());
    // 에라토스테네스의 체를 미리 사용한다.
    IsPrime();
    
    // 알고리즘을 사용해 조합을 만든다.
    do
    {
        Sum = 0;
        // 50개 이하이므로 시간 복잡도는 O(N^2)도 괜찮으리라 판단된다.
        for(int IDX = 0; IDX < UsingSize; ++IDX)
        {
            if(Using[IDX])
            {
                Sum += Nums[IDX];
            }
        }
        
        // 소수인지를 판별한다.
        //if(IsPrime(Sum))
        //{
        //    ++Answer;
        //}
        
        // 에라토스테네스의 체에서 걸러진 소수인 경우 합계가 소수이므로 판별된 소수 개수를 증가시킨다.
        if(Primes[Sum])
        {
             ++Answer;
        }
    } while(next_permutation(Using.begin(), Using.end()));

    return Answer;
}