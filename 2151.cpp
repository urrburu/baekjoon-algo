#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<cstring>
using namespace std;
char House[55][55];
int visit[55][55][4];
int n;
vector<pair<int, int>> Door;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			House[i][j] = s[j];
			if (House[i][j] == '#')Door.push_back({ i,j });
		}
	}
	memset(visit, 98765432, sizeof(visit));
	queue<tuple<int, int, int, int>> Que;
	Que.push(make_tuple(Door[0].first, Door[0].second, 0, -1));
	visit[Door[0].first][Door[0].second][0] = 0;
	visit[Door[0].first][Door[0].second][1] = 0;
	visit[Door[0].first][Door[0].second][2] = 0;
	visit[Door[0].first][Door[0].second][3] = 0;
	while (!Que.empty()) {
		int x, y, mir, prev;
		tie(x, y, mir, prev) = Que.front(); Que.pop();
		if (prev == -1) {
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i]; int ny = y + dy[i];
				if (!OOB(nx, ny) && House[nx][ny] != '*' && visit[nx][ny][i] > mir) {
					Que.push({ nx,ny,mir,i });
					visit[nx][ny][i] = mir;
				}
			}
		}
		else {
			int nx = x + dx[prev]; int ny = y + dy[prev];
			if (!OOB(nx, ny) && House[nx][ny] != '*' && visit[nx][ny][prev] > mir) {
				Que.push({ nx,ny,mir,prev });
				visit[nx][ny][prev] = mir;
			}
			if (House[x][y] == '!') {
				int dir = (prev + 1) % 4;
				int nx = x + dx[dir]; int ny = y + dy[dir];
				if (!OOB(nx, ny) && House[nx][ny] != '*' && visit[nx][ny][dir] > mir + 1) {
					Que.push({ nx,ny,mir + 1,dir });
					visit[nx][ny][dir] = visit[x][y][prev] + 1;
				}

				dir = (prev + 2) % 4;
				nx = x + dx[dir]; ny = y + dy[dir];
				if (!OOB(nx, ny) && House[nx][ny] != '*' && visit[nx][ny][dir] > mir + 1) {
					Que.push({ nx,ny,mir + 1,dir });
					visit[nx][ny][dir] = mir + 1;
				}
				dir = (prev + 3) % 4;
				nx = x + dx[dir]; ny = y + dy[dir];
				if (!OOB(nx, ny) && House[nx][ny] != '*' && visit[nx][ny][dir] > mir + 1) {
					Que.push({ nx,ny,mir + 1,dir });
					visit[nx][ny][dir] = mir + 1;
				}
			}
		}
	}
	int ans = 987654321;
	for (int i = 0; i < 4; ++i) {
		ans = min(visit[Door[1].first][Door[1].second][i], ans);
	}
	cout << ans << "\n";
}