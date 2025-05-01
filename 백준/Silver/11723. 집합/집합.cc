#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long M = 0;
	cin >> M;

	string Expression;
	int x = 0, S = 0;
	while(M--)
	{
		cin >> Expression;
		if (Expression == "add")
		{
			cin >> x;
			S |= (1 << x);
		}
		else if (Expression[0] == 'r')
		{
			cin >> x;
			S &= ~(1 << x);
		}
		else if (Expression[0] == 'c')
		{
			cin >> x;
			if(S & (1 << x))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (Expression[0] == 't')
		{
			cin >> x;
			S ^= (1 << x);
		}
		else if (Expression[0] == 'e')
		{
			S = 0;
		}
		else
		{
			S = (1 << 21) - 1;
		}
	}
}