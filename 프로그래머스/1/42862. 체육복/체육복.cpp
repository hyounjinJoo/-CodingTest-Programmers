#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // n : 학생 수
    // lost : 도난당한 자들의 번호
    // reserve : 여유 1개씩 더 가져온 친구
    // 번호의 앞, 뒤에만 빌려줄 수 있음.
    // 도난당한 자의 번호가 reserve에 있을 수 있음.
    // 번호는 1부터 시작
    
    // 학생 수 만큼 배열 선언
    vector<int> Student(n, 1);
    for(int Nth : lost)
    {
        --Student[Nth - 1];
    }
    
    for(int Nth : reserve)
    {
        ++Student[Nth - 1];
    }
    
    for(int IDX = 0; IDX < n; ++IDX)
    {
        if(Student[IDX] >= 1)
        {
            continue;            
        }
        
        // 학생을 자기 앞 뒤랑 비교
        if(IDX - 1 >= 0 && Student[IDX - 1] > 1)
        {
            --Student[IDX - 1];
            ++Student[IDX];
        }
        else if(IDX + 1 < n && Student[IDX + 1] > 1)
        {
            --Student[IDX + 1];
            ++Student[IDX];            
        }        
    }
    
    int answer = n;
    for(int Nth : Student)
    {
        if(0 == Nth)
        {
            --answer;
        }
    }
    
    return answer;
}