#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, m, answer;
int mark[101][101];
int Map[101][101];
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
bool check_cell(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (!OOB(nx, ny) && mark[nx][ny] == 1 && Map[nx][ny] == 0) {
			cnt++;
		}
	}
	if (cnt >= 2)return true;
	return false;
}
void prev_bfs() {
	memset(mark, 0, sizeof(mark));
	queue<pair<int, int> > q;
	q.push({ 0,0 });
	mark[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (!OOB(nx, ny) && Map[nx][ny] == 0 && mark[nx][ny] == 0) {
				q.push({ nx,ny });	mark[nx][ny] = 1;
			}
		}
	}
}
bool check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] == 1)return true;
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> Map[i][j];
		}
	}
	int cnt = 0;
	while (check()) {
		cnt++;
		prev_bfs();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (check_cell(i, j)) { Map[i][j] = 0; }
			}
		}

	}
	cout << cnt << " ";
}
//백조의 호수 생각하면서 좀 어렵게 처음 생각했던 문제. 
//하지만 1트솔 했다. 좀 허무하긴 한데. 
//역시 관건은 문제 정의에 충실한거 같다.
//문제를 잘 읽자!
