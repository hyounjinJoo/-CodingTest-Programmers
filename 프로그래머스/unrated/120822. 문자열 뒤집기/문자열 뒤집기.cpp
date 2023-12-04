#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    // 매개변수 my_string
    // my_string을 역순으로 뒤집을 것.
    // 1<= length <= 1000
    std::reverse(my_string.begin(), my_string.end());
    
    return my_string;
}