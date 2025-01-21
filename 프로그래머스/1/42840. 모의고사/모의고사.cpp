#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // 1번 수포자
    vector<int> Human1st = {1, 2, 3, 4, 5};
    vector<int> Human2nd = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> Human3rd = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int Count1 = 0, Count2 = 0, Count3 = 0;
    size_t QuestionMax = answers.size();
    int Human1Size = Human1st.size();
    int Human2Size = Human2nd.size();
    int Human3Size = Human3rd.size();
    int QuestionAnswer = 0;
    for(size_t IDX = 0; IDX < QuestionMax; ++IDX)
    {
        QuestionAnswer = answers[IDX];
        if(QuestionAnswer == Human1st[IDX % Human1Size]) ++Count1;
        if(QuestionAnswer == Human2nd[IDX % Human2Size]) ++Count2;
        if(QuestionAnswer == Human3rd[IDX % Human3Size]) ++Count3;        
    }
    
    if(Count1 == Count2 && Count2 == Count3)
    {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);        
    }
    else if(Count1 == Count2 && Count1 > Count3)
    {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(Count2 == Count3 && Count2 > Count1)
    {
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(Count1 == Count3 && Count1 > Count2)
    {
        answer.push_back(1);
        answer.push_back(3);
    }    
    else if(Count1 > Count2 && Count1 > Count3)
    {
        answer.push_back(1);
    }
    else if(Count2 > Count1 && Count2 > Count3)
    {
        answer.push_back(2);
    }
    else if(Count3 > Count2 && Count3 > Count1)
    {
        answer.push_back(3);
    }
    
    return answer;
}