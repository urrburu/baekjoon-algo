#include<iostream>

#include<queue>
#include<cstring>

using namespace std;
char board[55][55];
int visit[55][55];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
void bfs() {
	memset(visit, 98765432, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (!OOB(nx, ny)) {
				//cout << nx << " " << ny << " " << " \n";
				if (board[nx][ny] == '1' && visit[nx][ny] > visit[x][y]) {
					q.push({ nx,ny });
					visit[nx][ny] = visit[x][y];
				}
				else if (board[nx][ny] == '0' && visit[nx][ny] > visit[x][y] + 1) {
					q.push({ nx,ny });
					visit[nx][ny] = visit[x][y] + 1;
				}
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}*/
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			board[i][j] = s[j];
		}
	}
	bfs();

	cout << visit[n - 1][n - 1] << "\n";
}