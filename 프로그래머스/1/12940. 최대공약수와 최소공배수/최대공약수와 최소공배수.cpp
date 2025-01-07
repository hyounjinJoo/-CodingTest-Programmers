#include <string>
#include <vector>

using namespace std;

void swap(int& n, int& m)
{
    int temp = n;
    n = m;
    m = temp;
}

int gcd(int n, int m)
{
    int r = n % m;
    if(r == 0)
        return m;
    
    return gcd(m, r);    
}

int lcm(int n, int m, int gcd)
{
    return n * m / gcd;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(m > n) swap(n, m);
    
    answer.push_back(gcd(n, m));    
    answer.push_back(lcm(n, m, answer[0]));
    
    return answer;
}