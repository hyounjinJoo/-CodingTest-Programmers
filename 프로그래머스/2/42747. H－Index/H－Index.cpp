#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [첫 번째 풀이 생각]
// H-index 과학자의 생산성과 영향력 나타내는 지표
// h를 구한다
// n(논문 편 수), h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면
// h의 최댓값이 이 과학자의 h index
// 예시 :
// 3, 0, 6, 1, 5 ===> 3
// 논문 편수는 n : 5
// 그 중 3편이 3회 이상 인용
// 6 5 3 1 0
// 
// 해결 방법
// 정렬 수행
// n(5)에서 감소시켜 나가면서
// 조건 1 : n의 값이 논문의 인덱스 + 1 이상이고
// 조건 2 : 해당 인덱스 위치의 값이 n값 이상이면
// 조건을 충족한다.
// 5.... 0(6) 1 만족, 2 만족.... n 1 감소
// 4.... 1(5) 1 만족, 2 만족.... n 1 감소
// 3.... 2(3) 1 만족, 2 만족.... n 1 감소
// 2.... 3(1) 1 불만족.... n 1 증가. 반복 중지

// [두 번째 풀이 생각]
//  0   1   2   3   4   5 
//  6   5   3   3   1   0
// 1: 인덱스의 값(0)이 6보다 작다
// 2: 인덱스의 값(1)이 5보다 작다
// 3: 인덱스의 값(2)이 3보다 작다
// 4: 인덱스의 값(3)이 3보다 작거나 같다 하지만 h인덱스는 아니다.

// 결론 : 인덱스 + 1의 값이 논문 인용 횟수의 값보다 작거나 같으면 Answer를 증가시켜준다.
int solution(vector<int> Citations) {
    sort(Citations.begin(), Citations.end(), greater<int>());

    int Answer = 0;
    int Amount = Citations.size();
    for(int Idx = 0; Idx < Amount; ++Idx)
    {
        if(Idx + 1 <= Citations[Idx]) 
        {
            ++Answer;
        }
        else
        {
            break;    
        }
    }
    
    return Answer;
}