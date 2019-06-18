#include<algorithm>
#include<iostream>
#include<vector>
#include <string.h>
#define MAX 51
using namespace std;

int map[MAX][MAX] = { 0, };
bool chk[MAX][MAX] = { false, };
vector<int> answer;
int c,n,m,k;
int cnt;
int dir_r[4] = { 1,-1,0,0 };
int dir_c[4] = { 0,0,-1,1 };

int dfs(int r,int c) {
	chk[r][c] = true;
	for (int k = 0; k < 4; ++k) {
		int nr = r + dir_r[k];
		int nc = c + dir_c[k];
		if (nr >= 0 && nr < m && nc >= 0 && nc < n ) {
			if (chk[nr][nc] == false && map[nr][nc] == 1) {
				dfs(nr, nc);
			}
		}
	}
	return 0;
}

int main() {
	cin >> c;
	for (int test_case = 0; test_case < c; ++test_case) {
		cnt = 0;
		cin >> m >> n >> k;
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));
		while (k) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
			k--;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (chk[i][j] == false && map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	
	
	return 0;
}