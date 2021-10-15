#include<iostream>
#include<vector>

using namespace std;
int Max_ans = 0;
int Temp_ans = 0;
bool Occupy[6][6] = { false, };
int Board[6][6];
int n, m;
int dx[4][2] = { {-1,0},{-1,0},{0,1},{0,1} };
int dy[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
void dfs(int x, int y) {
	Occupy[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int ox = x + dx[i][0];
		int tx = x + dx[i][1];
		int oy = y + dy[i][0];
		int ty = y + dy[i][1];
		if (!OOB(ox, oy) && !OOB(tx, ty) && Occupy[ox][oy] == false && Occupy[tx][ty] == false) {
			Occupy[ox][oy] = true;
			Occupy[tx][ty] = true;
			Temp_ans += (Board[x][y] * 2 + Board[ox][oy] + Board[tx][ty]);
			Max_ans = max(Max_ans, Temp_ans);
			for (int iter = x; iter < n; ++iter) {
				for (int j = (iter == x ? y : 0); j < m; ++j) {
					if (Occupy[iter][j] == false) {
						dfs(iter, j);
					}
				}
			}
			Temp_ans -= (Board[x][y] * 2 + Board[ox][oy] + Board[tx][ty]);
			Occupy[ox][oy] = false;
			Occupy[tx][ty] = false;
		}
	}
	Occupy[x][y] = false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> Board[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Occupy[i][j] == false) {
				dfs(i, j);
			}
		}
	}
	cout << Max_ans << "\n";
}