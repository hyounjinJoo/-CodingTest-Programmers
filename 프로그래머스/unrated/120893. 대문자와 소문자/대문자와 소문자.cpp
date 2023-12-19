#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    int length = my_string.size();
    
    // A면 a - A 만큼을 더해주면 된다.
    // a면 a - A 만큼을 빼주면 된다.
    // 'Z'보다 작거나 같으면 차이를 더하고
    // 'Z'보다 크다면 차이를 뺀다.
    char difference = 'a' - 'A';
    for(int index = 0; index < length; ++index)
    {
        if('Z' >= my_string[index])
        {
            my_string[index] += difference;
        }
        else
        {
            my_string[index] -= difference;
        }
    }
    
    return my_string;
}