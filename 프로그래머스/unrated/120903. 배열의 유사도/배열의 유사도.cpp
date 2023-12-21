#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    int s1Count = static_cast<int>(s1.size());
    int s2Count = static_cast<int>(s2.size());
    
    for(int indexS1 = 0; indexS1 < s1Count; ++indexS1)
    {
         for(int indexS2 = 0; indexS2 < s2Count; ++indexS2)
         {
             if(s1[indexS1] == s2[indexS2])
             {
                 ++answer;
             }
         }   
    }
    
    return answer;
}