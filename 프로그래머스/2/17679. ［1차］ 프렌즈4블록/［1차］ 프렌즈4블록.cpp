#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void fillEmpty(int m, int n, vector<string>& board) {// 빈공간 내려주는 함수
    for (int j=0; j<n; j++) {
        string tmp = "";
        for (int i=m-1;i>=0;i--) if (board[i][j] != ' ') tmp += board[i][j];// 밑에서 부터 거꾸로 들어있는 블록 저장
        int i = m-1;
        for (auto c : tmp) board[i--][j] = c;// 밑에서 부터 채워주고
        for (; i>=0; i--) board[i][j] = ' ';// 윗부분은 공백으로 채워준다.
    }
}

bool is_hit(int i, int j, vector<string>& board, vector<vector<bool>>& vis) {
    if (board[i][j] != board[i+1][j] ||
        board[i][j] != board[i][j+1] ||
        board[i][j] != board[i+1][j+1]) return false ;// 적합하지 않다면
    vis[i][j] = true;
    vis[i+1][j] = true;
    vis[i][j+1] = true;
    vis[i+1][j+1] = true;
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    
    while (1) {
        bool done = true ;
        fill(vis.begin(), vis.end(), vector<bool>(n, false));// 방문 배열 초기화
        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n-1; j++) {
            	// 공백이 아니고 조건에 부합한다면 사각형부분을 방문체크해주고 끝나지 않았음으로 플래그를 바꿔준다.
                if (board[i][j] != ' ' && is_hit(i, j, board, vis)) done = false;
            }
        }
        if (done) break;// 더이상 부합하는 사각형이 없다면
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (vis[i][j]) board[i][j] = ' ';// 조건에 부합하는 부분들 전부 공백으로 바꿔준다.
            }
        }
        fillEmpty(m, n, board);// 빈공간 내려주기
    }
    for (auto s : board) {
        for (auto c : s) if (c == ' ') answer++;
    }
    return answer;
}