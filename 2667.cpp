#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#define MAX 26
using namespace std;

int map[MAX][MAX] = { 0, };
bool chk[MAX][MAX] = { false, };
vector<int> area;
int n;
int cnt, a_cnt;
int dir_r[4] = { 1,-1,0,0 };
int dir_c[4] = { 0,0,-1,1 };

int dfs(int r,int c) {
	chk[r][c] = true;
	for (int k = 0; k < 4; ++k) {
		int nr = r + dir_r[k];
		int nc = c + dir_c[k];
		if (nr >= 0 && nr < n && nc >= 0 && nc < n ) {
			if (chk[nr][nc] == false && map[nr][nc] == 1) {
				dfs(nr, nc);
				a_cnt++;
			}
		}
	}
	return 0;
}

int main() {
	cnt = 0; a_cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		
		for (int j = 0; j < n; ++j) {
	
			if (chk[i][j] == false && map[i][j] == 1) {
				dfs(i, j); 
				cnt++; a_cnt++;
			}
			if(a_cnt)area.push_back(a_cnt);
			a_cnt = 0;
		}
	}
	sort(area.begin(), area.end());
	cout << cnt << " ";
	for (int i = 0; i < area.size(); ++i) {
		cout << area[i] << " ";
	}
	return 0;
}