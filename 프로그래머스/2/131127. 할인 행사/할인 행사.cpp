#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{   
    int answer = 0;
    
    //vector<int> Result;
    //Result.resize(discount.size());
    vector<int> TempNumber;
    
    for(int i = 0; i < discount.size(); ++i)
    {
        //std::copy(number, TempNumber);
        TempNumber = number;        
        for(int j = 0; j < 10; ++j)
        {
            // 예외처리
            if(i + j > discount.size())
            {
                break;
            }
            
            for(int k = 0; k < want.size(); ++k)
            {
                // 현재 일수(j)와 시작 일자(i)를 더한 날의 품목과 내가 가진 품목 비교
                // 일치 여부 비교
                // 반복문 탈출시키고 다음날 시작
                if(want[k] == discount[i + j])
                {
                    if(0 < TempNumber[k])
                    {
                        --TempNumber[k];
                        break;
                    }
                }
            }
        }
        
        int RemainPurchase = 0;
        for(int TempNumIDX = 0; TempNumIDX < TempNumber.size(); ++TempNumIDX)
        {
            RemainPurchase += TempNumber[TempNumIDX];
        }

        if(RemainPurchase == 0)
        {
            ++answer;
        }
    }
    
    return answer;
}