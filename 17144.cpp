//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//int room[51][51];
//int nxt_room[51][51];
//vector<pair<int, int>> pure;
//int R, C, T;
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//bool OOB(int x, int y) { return x < 0 || y < 0 || x >= R || y >= C; }
//void one() {
//	for (int i = 0; i < R; ++i) {
//		for (int j = 0; j < C; ++j) {
//			nxt_room[i][j] = 0;
//			if (room[i][j] > 0) {
//				int dust = room[i][j] / 5;
//				for (int it = 0; it < 4; ++it) {
//					int nx = i + dx[it];int ny = j + dy[it];
//					if (!OOB(nx, ny) && room[nx][ny] != -1) {			nxt_room[nx][ny] += dust; room[i][j] -= dust;					}
//				}
//			}
//		}
//
//	}
//	for (int i = 0; i < R; ++i) {
//		for (int j = 0; j < C; ++j) {
//			if (room[i][j] > 0) {				nxt_room[i][j] += room[i][j];			}
//		}
//	}
//	for (int i = 0; i < R; ++i) {
//		for (int j = 0; j < C; ++j) {
//			room[i][j] = nxt_room[i][j];
//		}
//	}
//}
//void two() {
//	memset(nxt_room, 0, sizeof(nxt_room));
//	int up_x = pure[0].first, up_y = pure[0].second;
//	int down_x = pure[1].first, down_y = pure[1].second;
//	int dust = 0;
//	do {
//		 nxt_room[up_x][up_y+1] = room[up_x][up_y]; up_y++;
//	} while (up_y < C-1);
//	
//	do {
//		nxt_room[up_x-1][up_y] = room[up_x][up_y]; up_x--;
//	} while (up_x > 0);
//	
//	do {
//		 nxt_room[up_x][up_y-1] = room[up_x][up_y]; up_y--;
//	} while (up_y >0);
//	
//	do {
//		nxt_room[up_x + 1][up_y] = room[up_x][up_y]; up_x++;
//	} while (up_x != pure[0].first && up_y != pure[0].second);
//
//
//	do {
//		room[down_x][down_y] = 0; down_y++;
//	} while (down_y < C);
//	down_y--;
//	do {
//		room[down_x][down_y] = 0; down_x++;
//	} while (down_x < R);
//	down_x--;
//	do {
//		room[down_x][down_y] = 0; down_y--;
//	} while (down_y >= 0);
//	down_y++;
//	do {
//		room[down_x][down_y] = 0; down_x++;
//	} while (down_x != pure[1].first && down_y != pure[1].second);
//}
//
//int main() {
//	cin >> R >> C >> T;
//	for (int i = 0; i < R; ++i) {
//		for (int j = 0; j < C; ++j) {
//			cin >> room[i][j];
//			if (room[i][j] == -1)pure.push_back({ i,j });
//		}
//
//	}
//	while (T--) {
//		for (int i = 0; i < R; ++i) {
//			for (int j = 0; j < C; ++j) {
//				cout << room[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
//		one();
//		for (int i = 0; i < R; ++i) {
//			for (int j = 0; j < C; ++j) {
//				cout << room[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
//		two();
//		for (int i = 0; i < R; ++i) {
//			for (int j = 0; j < C; ++j) {
//				cout << room[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
//	}
//	int dust = 0;
//	for (int i = 0; i < R; ++i) {
//		for (int j = 0; j < C; ++j) {
//			dust += room[i][j];
//		}
//
//	}
//	cout << dust << "\n";
//}


#include <iostream>
#include <algorithm>
using namespace std;
int a[50][50];
int b[50][50];
int n, m;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
void go(int sx, int sy, int z) {
	int prev = 0;
	int x = sx;
	int y = sy + 1;
	int k = 0;
	while (true) {
		if (x == sx && y == sy) break;
		swap(prev, a[x][y]);
		x += dx[k];
		y += dy[k];
		if (x < 0 || y < 0 || x >= n || y >= m) {
			x -= dx[k];
			y -= dy[k];
			k += z;
			k %= 4;
			x += dx[k];
			y += dy[k];
		}
	}
}
int main() {
	int t;
	cin >> n >> m >> t;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				x = i;
				y = j;
			}
		}
	}
	x -= 1;
	while (t--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] <= 0) continue;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] >= 0) {
						cnt += 1;
					}
				}
				if (cnt > 0) {
					int val = a[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] >= 0) {
							b[nx][ny] += val;
						}
					}
					a[i][j] = a[i][j] - cnt * val;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == -1) continue;
				a[i][j] += b[i][j];
				b[i][j] = 0;
			}
		}
		go(x, y, 1);
		go(x + 1, y, 3);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= 0) {
				ans += a[i][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

