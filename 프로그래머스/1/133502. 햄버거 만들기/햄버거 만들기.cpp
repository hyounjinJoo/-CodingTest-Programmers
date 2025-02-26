#include <string>
#include <vector>
#include <stack>

using namespace std;

int FindNextMaterial(const vector<int> ingredient, int Idx)
{
    while(ingredient[Idx] == 0)
    {
        --Idx;
    }
    
    return ingredient[Idx];
}

int solution(vector<int> ingredient) {
    int answer = 0;
    
    // 함께 일을 하는 다른 직원들이 햄버거에 들어갈 재료를 조리해 주면 조리된 순서대로 상수의 앞에 아래서부터 위로 쌓이게 되고 -> stack?
    // 정해진 순서(아래서부터, 빵 – 야채 – 고기 - 빵)로 쌓인 햄버거만 포장
    // 1231
    // 재료의 높이는 무시
    //  [야채, 빵, 빵, 야채, 고기, 빵, 야채, 고기, 빵]일 때, 
    // 상수는 여섯 번째 재료가 쌓였을 때, 세 번째 재료부터 여섯 번째 재료를 이용하여 햄버거를 포장
    // 아홉 번째 재료가 쌓였을 때, 두 번째 재료와 일곱 번째 재료부터 아홉 번째 재료를 이용하여 햄버거를 포장
    
    // stack 2개를 써서 풀었다.    
    stack<int> Current;
    stack<int> Test;
    for(int& Material : ingredient)
    {
        Current.push(Material);
        if(Current.size() > 3 && Current.top() == 1)
        {
            Test.push(Current.top());
            Current.pop();
            if(Current.top() == 3)
            {
                Test.push(Current.top());
                Current.pop();
                if(Current.top() == 2)
                {
                    Test.push(Current.top());
                    Current.pop();
                    if(Current.top() == 1)
                    {
                        ++answer;
                        Current.pop();
                        while(!Test.empty()) Test.pop();
                    }
                    else
                    {
                        while(!Test.empty())
                        {
                            Current.push(Test.top());
                            Test.pop();
                        }
                    }
                }
                else
                {
                    while(!Test.empty())
                    {
                        Current.push(Test.top());
                        Test.pop();
                    }
                }                
            }
            else
            {
                while(!Test.empty())
                {
                    Current.push(Test.top());
                    Test.pop();
                }
            }
        }
    }
    return answer;
}