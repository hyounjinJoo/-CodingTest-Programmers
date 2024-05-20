#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> Numbers;
    stringstream sstream(s);
    string Number;
    
    while(getline(sstream, Number, ' '))
    {
        Numbers.push_back(stoi(Number));
    }
    
    sort(Numbers.begin(), Numbers.end());
    
    answer = to_string(Numbers.front()) + " " + to_string(Numbers.back());
    
    return answer;
}