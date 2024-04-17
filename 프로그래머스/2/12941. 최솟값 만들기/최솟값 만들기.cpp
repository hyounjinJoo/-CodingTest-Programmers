#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    size_t SizeA = A.size();
    
    int Temp = 0;
    for(int Idx = 0; Idx < SizeA; ++Idx)
    {
        answer += (A[Idx] * B[Idx]);
    }
    
    return answer;
}