#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    size_t Card1CurrentIDX = 0;
    size_t Card2CurrentIDX = 0;
    size_t GoalMax = goal.size();
    size_t Card1Max = cards1.size();
    size_t Card2Max = cards2.size();
    
    bool bNeedContinue = false;
    size_t CurrentGoalIDX = 0;
    while(CurrentGoalIDX != GoalMax)
    {
        bNeedContinue = false;
        if(Card1CurrentIDX < Card1Max && goal[CurrentGoalIDX] == cards1[Card1CurrentIDX])
        {
            Card1CurrentIDX++;
            CurrentGoalIDX++;
            bNeedContinue = true;
        }
        else if(Card2CurrentIDX < Card2Max && goal[CurrentGoalIDX] == cards2[Card2CurrentIDX])
        {
            Card2CurrentIDX++;
            CurrentGoalIDX++;
            bNeedContinue = true;
        }
        
        if(bNeedContinue)
        {
            if(CurrentGoalIDX == GoalMax)
            {
                return "Yes";
            }
        }
        else
        {
            return "No";
        }
    }
}