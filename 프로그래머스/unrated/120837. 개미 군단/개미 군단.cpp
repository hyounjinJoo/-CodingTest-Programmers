#include <string>
#include <vector>

using namespace std;

void ChangeHPAndAddAnt(int& hp, int& numberOfAnt, int attackPoint)
{
    numberOfAnt += static_cast<int>((hp) / attackPoint);
    hp = static_cast<int>((hp) % attackPoint);
}

int solution(int hp) {
    // General 5
    // Soldier 3
    // Worker 1
    
    int answer = 0;
    for(int attack = 5; attack > 0; attack -= 2)
    {
        ChangeHPAndAddAnt(hp, answer, attack);
    }
    
    return answer;
}