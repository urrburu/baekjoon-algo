#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
char map[55][55];
bool visit[55][55];
bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}
bool dfs(int x, int y, int px, int py, char color) {
	if (visit[x][y] == true) {
		return true;
	}
	visit[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!OOB(nx, ny) && color == map[nx][ny] && (nx != px || ny != py)) {
			if (dfs(nx, ny, x, y, color) == true)return true;
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visit[i][j] == false) {
				if (dfs(i, j, i, j, map[i][j])) {
					cout << "Yes" << "\n";
					return 0;
				}
			}
		}
	}
	cout << "No" << "\n";
	return 0;
}

//문제 90프로 풀고 결정적인 사이클 부분에서 실수. 
//사이클 거리가 얼마가 된다는걸 잡아내지 못하고
//한번 방문했던 노드를 다시 방문해서 길이 2짜리 사이클로 
//처음에 true가 나와버림
//예전 방문지점을 기억하거나 시작지점부터 사이클의 거리가 얼마나 되는지
//기록하는 저장형식을 만들어서 확인할것.