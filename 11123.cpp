#include <iostream>
#include <algorithm>
#include <queue>
#include<string>
using namespace std;
int h, w;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= h || y >= w; }
char map[101][101] = { {} };
bool visit[101][101] = { {} };
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] == '#' && !OOB(nx, ny) && visit[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
int main() {
	int test_case = 0;
	cin >> test_case;
	while (test_case--) {

		cin >> h >> w;
		int cnt = 0;
		for (int i = 0; i < 101; ++i) {
			for (int j = 0; j < 101; ++j) {
				map[i][j] = '.';
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < h; ++i) {
			string s; cin >> s;
			for (int j = 0; j < w; ++j) {
				map[i][j] = s[j];
			}
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (map[i][j] == '#' && visit[i][j] == false) {
					dfs(i, j);
					cnt += 1;
				}
			}
		}
		cout << cnt << "\n";
	}
}