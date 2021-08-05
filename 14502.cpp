#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int ans = 0;
int map[9][9];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> blank;
vector<pair<int, int>> virus;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				blank.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	vector<bool> combi(blank.size(), false);
	fill(combi.end() - 3, combi.end(), true);
	do {
		int copy_map[9][9];
		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < combi.size(); ++i) {
			if (combi[i] == true) {
				copy_map[blank[i].first][blank[i].second] = 1;
			}
		}
		for (int i = 0; i < virus.size(); ++i) {
			q.push({ virus[i].first, virus[i].second });
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && copy_map[nx][ny] == 0) {
					q.push({ nx,ny });
					copy_map[nx][ny] = 2;
				}
			}
		}
		int temp = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (copy_map[i][j] == 0)temp++;
			}
		}
		/*cout << temp << "\n";*/
		ans = max(ans, temp);
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << copy_map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
	} while (next_permutation(combi.begin(), combi.end()));


	cout << ans << "\n";

}