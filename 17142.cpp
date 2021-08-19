#include<iostream>
#include<algorithm>
#include<tuple>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n;
int map[55][55];
int scatt[55][55];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int, int>> virus;
int m;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
int count() {
	int step = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] != 1 && scatt[i][j] == -1)return 987654321;
			if (map[i][j] == 0) {
				step = max(scatt[i][j], step);
			}

		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << scatt[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << step << "\n\n";*/
	return step;
}
int main() {
	cin >> n >> m;
	int ans = 987654321;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });

			}
		}
	}
	vector<bool> sel(virus.size(), false);
	fill(sel.end() - m, sel.end(), true);
	do {
		queue<pair<int, int>> q;
		memset(scatt, -1, sizeof(scatt));
		for (int i = 0; i < sel.size(); ++i) {
			if (sel[i] == true) {
				q.push(virus[i]);
				scatt[virus[i].first][virus[i].second] = 0;
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!OOB(nx, ny) && scatt[nx][ny] == -1 && map[nx][ny] != 1) {
					q.push({ nx,ny });
					//cout << nx << " " << ny << " \n";
					scatt[nx][ny] = scatt[x][y] + 1;




					/*for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							cout << scatt[i][j] << " ";
						}
						cout << "\n";
					}
					cout << "\n";*/
				}
			}
		}
		int step = count();

		ans = min(ans, step);
	} while (next_permutation(sel.begin(), sel.end()));
	if (ans == 987654321) { cout << -1 << "\n"; return 0; }
	cout << ans << "\n";
}
//
//전부 세어줄 필요는 없다는 점을 기억할 것. 
//만약 바이러스에 감염된 칸이 존재한다고 할때, 여기를 지나가는 과정이 
//퍼지는 과정에는 포함되지만
//원래 감염되어있던 칸이므로 감염시키는데 얼마가 걸리냐
//묻는다면 시간이 걸리지 않는다가 대답임
//그러므로 비활성 바이러스 칸은 카운트에서 빼야함 
//이 점만 캐치한다면 풀 수 있는 문제. 
//더불어 memset과 fill 함수에 대해서도 다시 공부가 필요