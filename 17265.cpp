#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_num = 987654321;
int max_num = -987654321;
char board[6][6];
int n;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
void dfs(int x, int y, int ans, char prev) {
	if (x == n - 1 && y == n - 1) {
		min_num = min(min_num, ans); max_num = max(max_num, ans); return;
	}
	for (int i = 0; i < 2; ++i) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (!OOB(nx, ny)) {
			if (board[nx][ny] >= '0' && board[nx][ny] <= '9') {
				if (prev == '+') { dfs(nx, ny, ans + (board[nx][ny] - '0'), board[nx][ny]); }
				else if (prev == '-') { dfs(nx, ny, ans - (board[nx][ny] - '0'), board[nx][ny]); }
				else if (prev == '*') { dfs(nx, ny, ans * (board[nx][ny] - '0'), board[nx][ny]); }
			}
			else {
				dfs(nx, ny, ans, board[nx][ny]);
			}
		}
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	dfs(0, 0, board[0][0] - '0', ' ');
	cout << max_num << " " << min_num << "\n";
}//다시 풀것. 간단한 문제인데 생각을 못함. 정리를 잘 할것