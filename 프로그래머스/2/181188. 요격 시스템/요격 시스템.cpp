#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int Start = 0;
constexpr int End = 1;

bool CompareTargetLastPos(const vector<int>& _Target1, const vector<int> & _Target2) {
    return _Target1[End] < _Target2[End];
}

int solution(vector<vector<int>> Targets) {
    int Answer = 0;
    int Last = -1;
    
    sort(Targets.begin(), Targets.end(), CompareTargetLastPos);
    
    for (auto Target : Targets) {
        if (Target[Start] < Last && Target[End] >= Last )
            continue;
        else {
            Last = Target[End];
            ++Answer;
        }
    }
    
    return Answer;
}