#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int dx[] = { 0,1,0,-1,0,0 };
int dy[] = { 1,0,-1,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int m, n, h;
bool OOB(int x, int y, int z) { return x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= h; }
int tomato[101][101][101];
int visited[101][101][101];
int check() {
	int ans = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				ans = (ans < visited[j][k][i] ? visited[j][k][i] : ans);
				//cout << visited[j][k][i] <<" "<< ans<<" ";
				if (tomato[j][k][i] != -1 && visited[j][k][i] == -1)return -1;
			}
			//cout << '\n';
		}
		//cout << "\n";
	}
	return ans;
}
int main() {
	memset(visited, -1, sizeof(visited));
	queue<tuple<int, int, int>> q;
	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> tomato[j][k][i];
				if (tomato[j][k][i] == 1) {
					q.push(make_tuple(j, k, i));
					visited[j][k][i] = 0;
				}
			}
		}
	}
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (!OOB(nx, ny, nz) && visited[nx][ny][nz] == -1 && tomato[nx][ny][nz] == 0) {
				q.push(make_tuple(nx, ny, nz));
				visited[nx][ny][nz] = visited[x][y][z] + 1;
			}
		}
	}
	int ans = check();
	cout << ans << '\n';
}