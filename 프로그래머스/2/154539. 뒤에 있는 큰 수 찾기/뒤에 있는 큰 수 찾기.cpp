#include <string>
#include <vector>
#include <stack>

using namespace std;

/* 케이스 20~23 통과X
vector<int> solution(vector<int> _InNumbers) {
    vector<int> OutAnswer;
    
    int SizeOfNums = _InNumbers.size();
    int ClosestGreaterNum = -1;
    for(int Idx = 0; Idx < SizeOfNums; ++Idx)
    {
        // 나보다 큰 수 중 가장 가까이인 수.
        for(int IdxAfterMe = Idx + 1; IdxAfterMe < SizeOfNums; ++IdxAfterMe)
        {
            if(_InNumbers[Idx] < _InNumbers[IdxAfterMe])
            {
                ClosestGreaterNum = _InNumbers[IdxAfterMe];
                break;
            }
        }        
            
        OutAnswer.push_back(ClosestGreaterNum);
        ClosestGreaterNum = -1;
    }
    
    return OutAnswer;
}
*/
#define NotFound -1

/*
DP로 푼 것
vector<int> solution(vector<int> _InNumbers) {
    vector<int> OutAnswer(_InNumbers.size(), NotFound);
    int SizeOfNums = _InNumbers.size();
    
    for(int Idx = SizeOfNums - 2; Idx >= 0; --Idx)
    {
        // 나보다 큰 수 중 가장 가까이인 수.
        for(int IdxAfterMe = Idx + 1; IdxAfterMe < SizeOfNums; ++IdxAfterMe)
        {
            // 나보다 큰 수가 발견되었다
            if(_InNumbers[Idx] < _InNumbers[IdxAfterMe])
            {
                OutAnswer[Idx] = _InNumbers[IdxAfterMe];
                break;
            }
            // 발견하지 못했다면... 내가 크거나 같은 경우이다
            else
            {
                // 나 다음 정답이 -1이면
                if(NotFound == OutAnswer[IdxAfterMe])
                {
                    // 일단 찾지 못한것으로 체크한다.
                    OutAnswer[Idx] = NotFound;
                    break;
                }     
                // 나 다음에서 정답으로 기록된 것이 나보다 크다면 변경해준다.
                else if(_InNumbers[Idx] < OutAnswer[IdxAfterMe])
                {
                    OutAnswer[Idx] = OutAnswer[IdxAfterMe];
                    break;
                }
            }
        }
    }
    
    return OutAnswer;
}
*/

// Stack 사용
vector<int> solution(vector<int> _InNumbers)
{
    int NumbersCount = _InNumbers.size();
    vector<int> Answer(NumbersCount, -1);
    stack<int> NumbersIndexes;
    
    for(int Idx = 0; Idx < NumbersCount; ++Idx)
    {
        // Stack에 저장되어 있는 이전 인덱스의 숫자가 현재 인덱스의 숫자보다 작다면
        // Answer 갱신, 갱신이 완료되었으므로 pop() 처리
        while((false == NumbersIndexes.empty()) &&
              (_InNumbers[NumbersIndexes.top()] < _InNumbers[Idx]))
        {
            Answer[NumbersIndexes.top()] = _InNumbers[Idx];
            NumbersIndexes.pop();
        }
        
        // 현재 인덱스의 Answer는 뒤에 나온 숫자에 의해 갱신되므로 나중으로 미뤄준다.
        NumbersIndexes.push(Idx);
    }
    
    return Answer;
}

