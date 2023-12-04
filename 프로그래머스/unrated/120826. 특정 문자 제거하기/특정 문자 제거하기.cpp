#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    auto iterBegin = my_string.begin();
    auto iterEnd = my_string.end();
    
    for(;iterBegin != iterEnd;)
    {
        if((*iterBegin) == letter[0])
        {
            iterBegin = my_string.erase(iterBegin);
        }
        else
        {
            ++iterBegin;
        }
    }
    
    return my_string;
}