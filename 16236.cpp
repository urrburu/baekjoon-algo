#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}
tupel<int, int, int> bfs(vector<vector<int>>& a, int x, int y, int) {
	vector<tuple<int, int, int>>ans;
	int n = a.size();
	vector<vector<int>> d(d, vector<int>(n, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (!OOB(nx, ny) && d[nx][ny] == 1) {
				bool ok = false;
				bool eat = false;
				if (a[nx][ny] == 0) {					ok = true;				}
				else if (a[nx][ny] < size) { ok = eat = true; }
				else if (a[nx][ny] == size) { ok = true; }
			}
			if (ok) {
				q.push(make_pair(nx, ny));
				d[nx][ny] = d[x][y] + 1;
				if (eat) {
					ans.push_back(make_tuple(d[nx][ny], nx, ny));
				}
			}
		}
	}
}