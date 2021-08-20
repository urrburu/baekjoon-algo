#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int n, m, k, r, c;
int mapp[21][21];
int cus[21][21];
vector<pair<pair<int, int>, pair<int, int>> > target;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 1 || y < 1 || x > n || y > n; }
tuple<int, int, int> take_cus(int x, int y) {
	vector<tuple<int, int, int>> v;
	queue<pair<int, int>> q;
	int visited[21][21];
	memset(visited, -1, sizeof(visited));
	q.push({ x,y });
	visited[x][y] = 0;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		if (cus[xx][yy] != 0) {

			//cout << visited[nx][ny]<<" "<< nx << " " << ny << "\n";
			v.push_back(make_tuple(visited[xx][yy], xx, yy));
		}
		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (!OOB(nx, ny) && mapp[nx][ny] == 0 && visited[nx][ny] == -1) {
				q.push({ nx,ny });
				visited[nx][ny] = visited[xx][yy] + 1;
			}

		}
	}
	if (v.empty())return make_tuple(-1, -1, -1);
	sort(v.begin(), v.end());

	int dis, tx, ty;
	tie(dis, tx, ty) = v[0];
	//cout << dis << " " << tx << " " << ty << "\n";
	cus[tx][ty] = 0;
	return v[0];
}
tuple<int, int, int> taxi_drive(int x, int y) {
	int tx, ty;
	for (int i = 0; i < target.size(); ++i) {
		if (target[i].first.first == x && target[i].first.second == y) {
			tx = target[i].second.first;
			ty = target[i].second.second;
		}
	}
	int visited[21][21];
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 0;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		if (xx == tx && yy == ty) {
			return make_tuple(visited[xx][yy], xx, yy);
		}
		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (!OOB(nx, ny) && visited[nx][ny] == -1 && mapp[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = visited[xx][yy] + 1;
				//cout << visited[nx][ny]<<" "<< nx << " " << ny << "\n";
			}
		}
	}
	return make_tuple(-1, -1, -1);
}
int main() {
	cin >> n >> m >> k;
	int x, y, dis;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> mapp[i][j];
		}
	}
	cin >> x >> y;
	for (int i = 1; i <= m; ++i) {
		int sx, sy, fx, fy;
		cin >> sx >> sy >> fx >> fy;
		cus[sx][sy] = i;
		target.push_back({ {sx,sy},{fx,fy} });
	}
	for (int i = 0; i < target.size(); ++i) {
		tie(dis, x, y) = take_cus(x, y);
		//cout << dis << " " << x << " " << y << "\n";
		k -= dis;
		if (dis == -1 || k <= 0) {
			cout << -1 << "\n";
			return 0;
		}
		tie(dis, x, y) = taxi_drive(x, y);
		//cout << dis << " " << x << " " << y << "\n";
		if (k < dis || dis == -1) {
			cout << -1 << "\n";
			return 0;
		}
		k += dis;
		//cout << k << "\n";
	}

	cout << k << "\n";
}