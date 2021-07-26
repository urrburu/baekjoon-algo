#include <iostream>
#include <vector>
#include<queue>

using namespace std;
int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[1001][1001] = { {0,} };
queue < pair<pair<int, int>, pair<int, int>>> que;
int bfs(int x, int y) {
	que.push(make_pair(make_pair(x, y), make_pair(1, 1)));
	int count = 987654321;
	while (!que.empty()) {
		int nx = que.front().first.first;
		int ny = que.front().first.second;
		int breakable = que.front().second.first;
		int step = que.front().second.second;
		que.pop();
		if (nx == n && ny == m && (count > step)) {
			count = step;
		}
		for (int i = 0; i < 4; ++i) {
			nx = nx + dx[i];
			ny = ny + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = 2;
					que.push(make_pair(make_pair(nx, ny), make_pair(breakable, ++step)));
					cout << nx << " " << ny << endl;
				}
				if (map[nx][ny] == 1 && breakable == 1) {
					que.push(make_pair(make_pair(nx, ny), make_pair(0, ++step)));
					map[nx][ny] = 2;
					cout << nx << " " << ny << endl;
				}
			}
		}


	}
	return count;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; ++j) {
			map[i][j + 1] = tmp[j] - '0';
		}
	}

	int result = bfs(1, 1);
	if (result == 987654321) {
		cout << -1;
		return 0;
	}
	cout << result;
	return 0;
}