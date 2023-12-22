#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
	int answer = 0;
	// 1 - 0
	double slope1 = static_cast<double>(dots[1][1] - dots[0][1]) / (dots[1][0] - dots[0][0]);
	// 3 - 2
	double slope2 = static_cast<double>(dots[3][1] - dots[2][1]) / (dots[3][0] - dots[2][0]);
	if (slope1 == slope2)
	{
		answer = 1;
	}


	// 2 - 0
	slope1 = static_cast<double>(dots[2][1] - dots[0][1]) / (dots[2][0] - dots[0][0]);
	// 3 - 1
	slope2 = static_cast<double>(dots[3][1] - dots[1][1]) / (dots[3][0] - dots[1][0]);
	if (slope1 == slope2)
	{
		answer = 1;
	}

	// 3 - 0
	slope1 = static_cast<double>(dots[3][1] - dots[0][1]) / (dots[3][0] - dots[0][0]);
	// 1 - 2
	slope2 = static_cast<double>(dots[1][1] - dots[2][1]) / (dots[1][0] - dots[2][0]);
	if (slope1 == slope2)
	{
		answer = 1;
	}

	return answer;
}