//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//int R, C;
//char board[1501][1501];
//char next_board[1501][1501];
//bool visit[1501][1501];
//vector<pair<int, int>> v;
//bool OOB(int x, int y) { return x < 0 || y < 0 || x >= R || y >= C; }
//bool check(int x, int y) {
//	visit[x][y] = true;
//	if (x == v[1].first && y == v[1].second)return true;
//	for (int i = 0; i < 4; ++i) {
//		int nx = x + dx[i]; int ny = y + dy[i];
//		if (!OOB(nx, ny) && board[nx][ny] != 'X' && visit[nx][ny] == false) {
//			visit[nx][ny] = true;
//			//cout << nx << " " << ny << " \n";
//			return check(nx, ny);
//		}
//	}
//	return false;
//}
//bool breaking(int x, int y) {
//	for (int i = 0; i < 4; ++i) {
//		int nx = x + dx[i]; int ny = y + dy[i];
//		if (board[nx][ny] == '.' || board[x][y] == '.')return true;
//	}
//	return false;
//}
//int main() {
//	cin >> R >> C;
//	for (int i = 0; i < R; ++i) {
//		string s; cin >> s;
//		for (int j = 0; j < C; ++j) {
//			board[i][j] = s[j];
//			if (board[i][j] == 'L')v.push_back({ i,j });
//		}
//	}
//	int day = 0;
//	while (!check(v[0].first, v[0].second)) {
//		memset(visit, false, sizeof(visit));
//		day++;
//		for (int i = 0; i < R; ++i) {
//			for (int j = 0; j < C; ++j) {
//				if (breaking(i, j)) { next_board[i][j] = '.'; }
//				else { next_board[i][j] = 'X'; }
//			}
//		}
//		for (int i = 0; i < R; ++i) {
//			for (int j = 0; j < C; ++j) {
//				board[i][j] = next_board[i][j];
//				//cout << next_board[i][j]<<" ";
//			}
//			//cout << "\n";
//		}
//		//cout << "\n";
//	}
//	cout << day << "\n";
//}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1501

int R, C;
int Swan_index[2][2];
bool Meet = false;
char arr[MAX][MAX];
bool visit[MAX][MAX];
queue <pair<int, int>> water;
queue <pair<int, int>> water_ice;
queue <pair<int, int>> swan;
queue <pair<int, int>> swan_ice;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Swan_BFS() {
	while (!swan.empty() && !Meet) {
		int x = swan.front().first; int y = swan.front().second;
		swan.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == '.') {
				visit[nx][ny] = true; swan.push(make_pair(nx, ny));
			}
			else if (arr[nx][ny] == 'L') {
				visit[nx][ny] = true;  Meet = true; break;
			}
			else if (arr[nx][ny] == 'X') {
				visit[nx][ny] = true; swan_ice.push(make_pair(nx, ny));
			}
		}
	}
}

void Water_BFS() {
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (arr[nx][ny] == 'X') {
				arr[nx][ny] = '.';
				water_ice.push(make_pair(nx, ny));
			}
		}
	}
}

void memset_arr() {
	while (!water_ice.empty()) water_ice.pop();
	while (!swan_ice.empty()) swan_ice.pop();
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> R >> C;

	int n = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 'X') water.push(make_pair(i, j));
			if (arr[i][j] == 'L') {
				Swan_index[n][0] = i; Swan_index[n][1] = j;
				n++;
			}
		}
	}

	int Day = 0;
	swan.push(make_pair(Swan_index[0][0], Swan_index[0][1]));
	visit[Swan_index[0][0]][Swan_index[0][1]] = true;
	while (!Meet) {
		Swan_BFS();
		if (Meet) break;
		Water_BFS();
		swan = swan_ice; water = water_ice;
		memset_arr();
		Day++;
	}
	cout << Day;
	return 0;
}