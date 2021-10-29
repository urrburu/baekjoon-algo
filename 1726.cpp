#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<tuple>
using namespace std;
int n, m;

int Board[101][101];
int Visit[101][101][4];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> Board[i][j];
		}
	}
	memset(Visit, 98765432, sizeof(Visit));

	int sx, sy, sdir; int ex, ey, edir;
	cin >> sx >> sy >> sdir; cin >> ex >> ey >> edir;
	queue<tuple<int, int, int, int>> que;
	if (sdir == 1) { sdir = 0; }//e
	if (sdir == 2) { sdir = 2; }//w
	if (sdir == 3) { sdir = 1; }
	if (sdir == 4) { sdir = 3; }
	if (edir == 1) { edir = 0; }
	if (edir == 2) { edir = 2; }
	if (edir == 3) { edir = 1; }
	if (edir == 4) { edir = 3; }
	que.push(make_tuple(sx - 1, sy - 1, sdir, 0));
	Visit[sx - 1][sy - 1][sdir] = 0;
	while (!que.empty()) {
		int x, y, dir, step;
		tie(x, y, dir, step) = que.front(); que.pop();
		int nx = x, ny = y;
		for (int iter = 0; iter < 3; ++iter) {
			nx += dx[dir], ny += dy[dir];
			if (Board[nx][ny] == 1)break;
			if (!OOB(nx, ny) && Visit[nx][ny][dir] > step + 1) {
				que.push(make_tuple(nx, ny, dir, step + 1));
				Visit[nx][ny][dir] = step + 1;
			}

		}
		int i = (dir + 1) % 4;
		if (Visit[x][y][i] > step + 1) {
			que.push(make_tuple(x, y, i, step + 1));
			Visit[x][y][i] = step + 1;
		}
		i = (dir + 3) % 4;
		if (Visit[x][y][i] > step + 1) {
			que.push(make_tuple(x, y, i, step + 1));
			Visit[x][y][i] = step + 1;
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Visit[i][j][0] > 200000) {
				cout << 0 << " ";
			}
			else {
				cout << Visit[i][j][0] << " ";
			}

		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Visit[i][j][1] > 200000) {
				cout << 0 << " ";
			}
			else {
				cout << Visit[i][j][1] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Visit[i][j][2] > 200000) {
				cout << 0 << " ";
			}
			else {
				cout << Visit[i][j][2] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Visit[i][j][3] > 200000) {
				cout << 0 << " ";
			}
			else {
				cout << Visit[i][j][3] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";*/
	cout << Visit[ex - 1][ey - 1][edir] << "\n";
}