#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    //dfja rdst ddetckdaccccdegk
    //0123 0123 0123
    string answer = "";
    
    int length = static_cast<int>(cipher.size());
    for(int index = 0; index < length; ++index)
    {
        if((index % code) == (code - 1))
        {
            answer.push_back(cipher[index]);
        }
    }
        
    return answer;
}