#include <iostream>

using namespace std;

int main(void) {
    // *의 높이, 너비가 1
    // *을 이용한 출력으로 직각 이등변 삼각형 그리기
    // 정수 n이 주어질 때 높이와 너비가 n인 직각 이등변 삼각형을 그려라
    int line;
    cin >> line;
    
    for(int lineNum = 0; lineNum < line; ++lineNum)
    {
        for(int printNum = 0; printNum < lineNum + 1; ++printNum)
        {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}