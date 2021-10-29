#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int n, k;
int Map[201][201] = { {0,} };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
int main() {
	int s, x, y;
	cin >> n >> k;
	vector<tuple<int, int, int>> virus;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> Map[i][j];
			if (Map[i][j] != 0)virus.push_back(make_tuple(Map[i][j], i, j));
		}
	}
	cin >> s >> x >> y;
	sort(virus.begin(), virus.end());
	queue<tuple<int, int, int, int>> que;
	for (int i = 0; i < virus.size(); ++i) { que.push(make_tuple(get<1>(virus[i]), get<2>(virus[i]), 0, get<0>(virus[i]))); }
	while (!que.empty() && s--) {
		int qs = que.size();
		while (qs--) {
			int xx, yy, time, num; tie(xx, yy, time, num) = que.front(); que.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = xx + dx[i]; int ny = yy + dy[i];
				if (!OOB(nx, ny) && Map[nx][ny] == 0) {
					que.push(make_tuple(nx, ny, time + 1, num));
					Map[nx][ny] = num;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << Map[i][j] << " ";

		}
		cout << " \n";
	}
	cout << Map[x - 1][y - 1] << "\n";
}