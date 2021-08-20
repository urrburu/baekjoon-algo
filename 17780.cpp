#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int board[13][13];
vector<int> knight[13][13];
vector<pair<int, int>> where;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
bool moving(int x, int y, int num, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (board[nx][ny] == 0) {
		for (int i = 0; i < knight[x][y].size(); ++i) {
			knight[nx][ny].push_back(knight[x][y][i]);
		}
		knight[x][y].clear();
	}
	else if (board[nx][ny] == 1) {
		for (int i = knight[x][y].size() - 1; i >= 0; --i) {
			knight[nx][ny].push_back(knight[x][y][i]);
		}
		knight[x][y].clear();

	}
	else if (board[nx][ny] == 2 || OOB(nx, ny)) {
		nx = x + dx[(dir + 2) % 4];
		ny = y + dy[(dir + 2) % 4];
		knight[x][y].push_back((dir + 2) % 4);
		for (int i = 0; i < knight[x][y].size(); ++i) {
			knight[nx][ny].push_back(knight[x][y][i]);
		}
		knight[x][y].clear();
	}
	if (knight[nx][ny].size() >= 4)return true;
	return false;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; ++i) {
		int x, y, d;
		cin >> x >> y >> d;
		knight[x][y].push_back(d);
		where.push_back({ x,y });
	}
	int time = 1000;
	while (time--) {
		for (int i = 0; i < where.size(); ++i) {
			int x = where[i].first;
			int y = where[i].second;
			moving(x, y, i, knight[x][y].front());
		}

	}
	cout << -1 << "\n";
	return 0;
}

#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int opposite(int dir) {
    if (dir == 0) return 1;
    if (dir == 1) return 0;
    if (dir == 2) return 3;
    return 2;
}
void go(vector<vector<vector<pair<int, int>>>>& a, vector<pair<int, int>>& where, int x, int y, int nx, int ny) {
    for (auto& p : a[x][y]) {
        a[nx][ny].push_back(p);
        where[p.first] = make_pair(nx, ny);
    }
    a[x][y].clear();
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<vector<pair<int, int>>>> a(n, vector<vector<pair<int, int>>>(n));
    vector<pair<int, int>> where(m);
    for (int i = 0; i < m; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        a[x - 1][y - 1].push_back(make_pair(i, dir - 1));
        where[i] = make_pair(x - 1, y - 1);
    }
    for (int turn = 1; turn <= 1000; turn++) {
        for (int k = 0; k < m; k++) {
            int x, y;
            tie(x, y) = where[k];
            if (a[x][y][0].first == k) { // bottom
                int dir = a[x][y][0].second;
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) { // in
                    if (board[nx][ny] == 2) {
                        a[x][y][0].second = opposite(dir);
                    }
                }
                else {
                    a[x][y][0].second = opposite(dir);
                }
                dir = a[x][y][0].second;
                nx = x + dx[dir];
                ny = y + dy[dir];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) { // in
                    if (board[nx][ny] == 0) {
                        go(a, where, x, y, nx, ny);
                    }
                    else if (board[nx][ny] == 1) {
                        reverse(a[x][y].begin(), a[x][y].end());
                        go(a, where, x, y, nx, ny);
                    }
                    if (a[nx][ny].size() >= 4) {
                        cout << turn << '\n';
                        return 0;
                    }
                }
                else { // out
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
