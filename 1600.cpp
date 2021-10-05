#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
#include<algorithm>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int hx[] = { 1, 2,2,1,-1,-2,-2,-1 };
int hy[] = { -2,-1,1,2, 2, 1,-1,-2 };
int Map[201][201];
bool Visit[201][201][31];
int k, n, m;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int bfs() {
	queue<tuple<int, int, int, int> > q;
	q.push(make_tuple(0, 0, 0, 0));
	Visit[0][0][0] = true;
	vector<int> Answer;
	while (!q.empty()) {
		int xx, yy, jump, step;
		tie(xx, yy, jump, step) = q.front(); q.pop();
		if (xx == n - 1 && yy == m - 1)return step;
		for (int i = 0; i < 8; ++i) {
			int nx = xx + hx[i]; int ny = yy + hy[i];
			if (!OOB(nx, ny) && Map[nx][ny] == 0 && k > jump && Visit[nx][ny][jump + 1] == false) {
				q.push(make_tuple(nx, ny, jump + 1, step + 1));
				Visit[nx][ny][jump + 1] = true;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i]; int ny = yy + dy[i];
			if (!OOB(nx, ny) && Map[nx][ny] == 0 && Visit[nx][ny][jump] == false) {
				q.push(make_tuple(nx, ny, jump, step + 1));
				Visit[nx][ny][jump] = true;
			}
		}
	}
	return -1;
}

int main() {
	cin >> k >> m >> n;
	//이 문제를 틀리는 주요 원인. 가로세로가 바뀌어있었다. 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> Map[i][j];
		}
	}
	memset(Visit, false, sizeof(Visit));
	int ans = bfs();
	cout << ans << "\n";
}