#include <vector>
#include <algorithm>
using namespace std;

// 소수의 정의 : 1과 자기 자신으로만 나눌 수 있는 수
bool IsPrime(int InNumber)
{
    bool Result = true;
    // 만약 1이거나 2라면 자기 자신으로 나눌 수 있으므로 참이다.
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
    // 알고리즘을 사용해 조합을 만든다.
    do
    {
        Sum = 0;
        // 50개 이하이므로 시간 복잡도는 O(N^2)도 괜찮으리라 판단된다.
        for(int IDX = 0; IDX < Using.size(); ++IDX)
        {
            if(Using[IDX])
            {
                Sum += Nums[IDX];
            }
        }
        
        // 소수인지를 판별한다.
        if(IsPrime(Sum))
        {
            ++Answer;
        }
    } while(next_permutation(Using.begin(), Using.end()));

    return Answer;
}