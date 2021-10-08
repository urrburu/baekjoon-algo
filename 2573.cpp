#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int Map[301][301];
int n, m;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int Check() {//2개이상 false 1개이하 true
	queue<pair<int, int> > q;
	int Visit[301][301] = { {0,} };
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] != 0 && Visit[i][j] == 0) {
				cnt++; q.push({ i,j }); Visit[i][j] = cnt;
				while (!q.empty()) {
					int x = q.front().first; int y = q.front().second; q.pop();
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k]; int ny = y + dy[k];
						if (!OOB(nx, ny) && Map[nx][ny] != 0 && Visit[nx][ny] == 0) {
							q.push({ nx,ny }); Visit[nx][ny] = cnt;
						}
					}
				}
			}

		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << Visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/
	return cnt;
}

void melt() {
	int Next[301][301] = { {0,} };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] == 0) {
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k]; int ny = j + dy[k];
					if (!OOB(nx, ny) && Map[nx][ny] > 0) { Next[nx][ny]--; }
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] != 0) {
				Next[i][j] += Map[i][j];
				if (Next[i][j] < 0)Map[i][j] = 0;
				else Map[i][j] = Next[i][j];
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> Map[i][j];
		}
	}
	int ans = 0;
	while (Check() == 1) {
		//cout << check() << " \n";
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << Map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		ans++;
		melt();
	}
	if (Check() >= 2)cout << ans << "\n";
	else {
		cout << 0 << "\n";
	}
	return 0;
}