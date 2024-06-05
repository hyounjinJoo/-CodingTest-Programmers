using namespace std;

int solution(int Number) {
    int Answer = Number + 1;
    int CountBit = __builtin_popcount(Number);
    int NextCountBit = __builtin_popcount(Answer);
    while(CountBit != NextCountBit)
    {
        ++Answer;
        NextCountBit = __builtin_popcount(Answer);
    }
    
    return Answer;
}