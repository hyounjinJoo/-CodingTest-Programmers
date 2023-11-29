#include <string>
#include <vector>

using namespace std;

void ChangeByLCM(int* numer, int* denom, int lcm);
int FindGCD(int num1, int num2);
int FindLCM(int num1, int num2, int gcd);

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
        
    vector<int> answer;
    int gcd = FindGCD(denom1, denom2);
    int lcm = FindLCM(denom1, denom2, gcd);

    ChangeByLCM(&numer1, &denom1, lcm);
    ChangeByLCM(&numer2, &denom2, lcm);
      
    
    int numerResult = numer1 + numer2;
    if(numerResult > denom1)
    {
        gcd = FindGCD(denom1, numerResult);
    }
    else
    {
        gcd = FindGCD(numerResult, denom1);        
    }
    
    if(gcd != denom1 || gcd != numerResult)
    {
        numerResult /= gcd;
        denom1 /= gcd;
    }    
    
    if(numerResult == denom1)
    {
        answer.push_back(1);
        answer.push_back(1);
    }
    else
    {
        answer.push_back(numerResult);
        answer.push_back(denom1);        
    }
    
    return answer;
}

void ChangeByLCM(int* numer, int* denom, int lcm)
{
    if((*denom) == lcm)
    {
        return;
    }
    
    *numer = (*numer) * (lcm / *denom); 
    *denom = lcm;
}

int FindGCD(int num1, int num2)
{
    if(num1 % num2 == 0)
    {
        return num2;
    }
    
    return FindGCD(num2, num1%num2);
}

int FindLCM(int num1, int num2, int gcd)
{
    return num1 * num2 / gcd;
}