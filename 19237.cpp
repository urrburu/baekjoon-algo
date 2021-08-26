#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cstring>


const int limit = 1000;
using namespace std;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int shark[21][21];
int shark_next[21][21];
int smell[21][21];
int smell_who[21][21];
int dir[401];
int priority[401][4][4];
int n, m, smell_time;
bool check_1() {
	int cnt = 0;
	int one = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (shark[i][j] > 0) {
				cnt++;
			}
			if (shark[i][j] == 1) {
				one++;
			}
		}
	}
	return cnt == 1;
}
void move_shark() {
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {
			shark_next[i][j] = 0;
			if (shark[i][j] > 0) {
				v.push_back(make_tuple(shark[i][j], i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto& t : v) {
		int no, x, y;
		tie(no, x, y) = t;
		int shark_dir = dir[no];
		bool ok = false;
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[priority[no][shark_dir][k]];
			int ny = y + dy[priority[no][shark_dir][k]];
			if (!OOB(nx, ny) && smell[nx][ny] == 0) {
				if (shark_next[nx][ny] == 0) {
					shark_next[nx][ny] = no;
					dir[no] = priority[no][shark_dir][k];
				}
				else {
					if (shark_next[nx][ny] > no) {
						shark_next[nx][ny] = no;
						dir[no] = priority[no][shark_dir][k];
					}
				}
				ok = true;
				break;
			}
			if (ok)break;
		}
		if (!ok) {
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[priority[no][shark_dir][k]];
				int ny = y + dy[priority[no][shark_dir][k]];
				if (!OOB(nx, ny) && smell[nx][ny] > 0 && smell_who[nx][ny] == no) {
					shark_next[nx][ny] = no;
					dir[no] = priority[no][shark_dir][k];
					ok = true;
					break;
				}
				if (ok)break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			shark[i][j] = shark_next[i][j];
			if (smell[i][j] > 0) {
				smell[i][j] -= 1;
			}
			if (smell[i][j] == 0) {
				smell_who[i][j] = 0;
			}
			if (shark[i][j] > 0) {
				smell[i][j] = smell_time;
				smell_who[i][j] = shark[i][j];
			}
		}
	}
}

int main() {
	cin >> n >> m >> smell_time;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> shark[i][j];
			if (shark[i][j] > 0) {
				smell[i][j] = smell_time;
				smell_who[i][j] = shark[i][j];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> dir[i];
		dir[i] -= 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> priority[i][j][k];
				priority[i][j][k] -= 1;
			}
		}
	}
	int ans = -1;
	for (int t = 1; t <= limit; t++) {
		move_shark();
		if (check_1()) {
			ans = t;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}