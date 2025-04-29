#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define EXPRESSION_1(dice) 10000 + (dice * 1000)
#define EXPRESSION_2(dice) 1000 + (dice * 100)
#define EXPRESSION_3(dice) dice * 100 

int main()
{
	vector<int> Numbers(3);
	for(int& Number : Numbers)
	{
		cin >> Number;
	}

	sort(Numbers.begin(), Numbers.end(), greater<int>());

	if(Numbers[0] == Numbers[1] && Numbers[1] == Numbers[2])
	{
		cout << EXPRESSION_1(Numbers[0]);
	}
	else if(Numbers[0] == Numbers[1])
	{
		cout << EXPRESSION_2(Numbers[0]);
	}
	else if(Numbers[1] == Numbers[2])
	{
		cout << EXPRESSION_2(Numbers[1]);
	}
	else
	{
		cout << EXPRESSION_3(Numbers[0]);
	}
}