#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int map[1001][1001];
int mov[1001][1001];
bool visited[1001][1001];
int n, m;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	vector<pair<int, int>> group;
	group.push_back({ x,y });
	visited[x][y] = true;
	int cnt = 1;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (!OOB(nx, ny) && map[nx][ny] == 0 && visited[nx][ny] == false) {
				cnt++;
				visited[nx][ny] = true;
				q.push({ nx,ny });
				group.push_back({ nx,ny });
				/*cout << nx << " " << ny << " \n";*/
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << mov[i][j];
		}
		cout << "\n";
	}*/
	for (int i = 0; i < group.size(); ++i) {
		mov[group[i].first][group[i].second] = cnt;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			map[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 0 && visited[i][j] == false) bfs(i, j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << mov[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num = 1;
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (!OOB(nx, ny)) {
						num += mov[nx][ny];
					}
				}
				cout << num % 10;
			}
			else { cout << 0; }
		}
		cout << "\n";
	}
}

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
int n, m;
int a[1000][1000];
bool check[1000][1000];
int group[1000][1000];
vector<int> group_size;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int sx, int sy) {
	int g = group_size.size();
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check[sx][sy] = true;
	group[sx][sy] = g;
	int cnt = 1;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && check[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					group[nx][ny] = g;
					cnt += 1;
				}
			}
		}
	}
	group_size.push_back(cnt);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
			check[i][j] = false;
			group[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && check[i][j] == false) {
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				cout << 0;
			}
			else {
				set<int> near;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (0 <= x && x < n && 0 <= y && y < m) {
						if (a[x][y] == 0) {
							near.insert(group[x][y]);
						}
					}
				}
				int ans = 1;
				for (int g : near) {
					ans += group_size[g];
				}
				cout << ans % 10;
			}
		}
		cout << '\n';
	}
	return 0;
}

#include<iostream>
#include<queue>
#include<set>
#include<map>
using namespace std;
int Map[1001][1001];
int visit[1001][1001];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
map<int, int> Area;
int n, m;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
void Bfs(int x, int y, int Num) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	visit[x][y] = Num;
	int areaCnt = 1;
	while (!que.empty()) {
		int xx = que.front().first;
		int yy = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i]; int ny = yy + dy[i];
			if (!OOB(nx, ny) && visit[nx][ny] == 0 && Map[nx][ny] == 0) {
				que.push({ nx,ny });
				visit[nx][ny] = Num;
				areaCnt++;
			}
		}
	}
	Area.insert({ Num, areaCnt });
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			Map[i][j] = s[j] - '0';
		}
	}
	int Numbering = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] == 0 && visit[i][j] == 0) {
				Bfs(i, j, Numbering);
				Numbering++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] == 1) {
				set<int> S;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (!OOB(nx, ny) && visit[nx][ny] != 0)S.insert(visit[nx][ny]);
				}
				int sum = 1;
				for (int al : S) { sum += Area.find(al)->second; sum %= 10; }
				cout << sum;
			}
			else {
				cout << 0;
			}
		}
		cout << "\n";
	}
	/*for (int iter = 0; iter < Area.size(); ++iter) {
		cout << Area[iter].first << " " << Area[iter].second << " \n";
	}*/
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << visit[i][j];
		}
		cout << "\n";
	}*/
}