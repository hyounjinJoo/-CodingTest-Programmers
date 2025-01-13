#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Index = 0;

bool compare(const string& left, const string& right)
{
    if(left[Index] == right[Index])
    {
        return left > right ? false : true;
    }
    
    return left[Index] < right[Index]; 
}

vector<string> solution(vector<string> strings, int n) {
    Index = n;
    sort(strings.begin(), strings.end(), compare);
    
    vector<string> answer = strings;
    
    return answer;
}