#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    // n : 참가자 수
    // words : 끝말잇기에 사용한 단어들이 순서대로 들어있는 배열
    
    // 가장 먼저 탈락하는 사람의 번호, 그 사람이 자신의 몇 번째 차례에 탈락하는지를 담아서 return
    vector<int> answer;
    
    int Size = words.size();
    bool bIsRepeat = false;
    bool bWrongStart = false;
    char EndAlphabet = NULL;
    
    int iter = 0;
    for(; iter < Size; ++iter)
    {
        // 1.check prev word
        for(int prevIter = 0; prevIter < iter; ++prevIter)
        {
            if(words[prevIter] == words[iter])
            {
                bIsRepeat = true;                
                break;
            }
        }
        if(true == bIsRepeat)
        {
            break;
        }
        
        // 2.check this word start correct
        if(NULL != EndAlphabet && EndAlphabet != words[iter][0])
        {
            bWrongStart = true;            
            break;
        }
        
        EndAlphabet = words[iter].back();
    }
    
    if(false == bIsRepeat && false == bWrongStart)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        // 0 1 2 3 4 5 6 7 8
        // 1 2 3 1 2 3 1 2 3
        // 1 1 1 2 2 2 3 3 3
        
        // 1 2 1 2 1 2 1 2 1
        // 1 1 2 2 3 3 4 4 5
        answer.push_back((iter % n) + 1);
        answer.push_back((iter / n) + 1);
    }

    return answer;
}