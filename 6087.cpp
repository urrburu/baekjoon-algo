#include<iostream>
#include<queue>
#include<vector>
using namespace std;
char map[101][101];
int visit[101][101];
int w, h;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int, int>> point;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= h || y >= w; }
int bfs(int x, int y) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {x,y},{-1,-1} });
	visit[x][y] = 0;
	while (!q.empty()) {
		int xx = q.front().first.first;
		int yy = q.front().first.second;
		int prev = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (!OOB(nx, ny) && map[nx][ny] != '*') {
				if (prev != i && visit[nx][ny] > cnt) {
					q.push({ {nx,ny},{i,cnt + 1} });
					visit[nx][ny] = cnt + 1;
				}
				else if (prev == i && visit[nx][ny] >= cnt) {
					q.push({ {nx,ny},{i,cnt} });
					visit[nx][ny] = cnt;
				}
				//이 부분에서 난점을 겪었던 코드이다.
				//만약 같은 점에서 카운트가 같더라도 들어온 방향이 다르다면 
				//두 방향을 모두 큐에 넣어서 계속 진행시켜야한다는걸
				//생각해줘야 했다. 
			}
		}
	}
	return visit[point[1].first][point[1].second];
}
int main() {
	cin >> w >> h;
	for (int i = 0; i < h; ++i) {
		string s; cin >> s;
		for (int j = 0; j < w; ++j) {
			map[i][j] = s[j];
			visit[i][j] = 987654321;
			if (map[i][j] == 'C') {
				point.push_back({ i,j });
			}
		}
	}
	int min_num = bfs(point[0].first, point[0].second);
	cout << min_num << "\n";
}