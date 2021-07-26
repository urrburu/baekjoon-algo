#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4] = { 1.0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> endpoint;
vector<pair<pair<int, int>, int>> cctv;// ���� ���� x,y��ǥ, �ڴ� cctv ����

void watch(int x, int y, int dir) {
	endpoint.push({ x,y });
	while (!endpoint.empty()) {
		int nx = endpoint.front().first;
		int ny = endpoint.front().second;
		watched[nx][ny] = 1;
		nx = nx + dx[dir];
		ny = ny + dy[dir];
		if ((map[nx][ny] == 0 && watched[nx][ny] == 0) || (map[nx][ny] != 0 && map[nx][ny] != 6)) {
			endpoint.push({ nx,ny });
		}
	}
}
void one(int x, int y, int dir) {// dir === 0,1,2,3
	watch(x, y, dir);
}
void two(int x, int y, int dir) {
	watch(x, y, dir % 4);
	watch(x, y, (dir + 2) % 4);
}
void three(int x, int y, int dir) {
	if (dir != 3) {
		watch(x, y, dir);
		watch(x, y, dir + 1);
	}
	else {
		watch(x, y, 0);
		watch(x, y, 3);
	}

}
void four(int x, int y, int except_dir) {
	if (except_dir == 0) {
		watch(x, y, 1);
		watch(x, y, 2);
		watch(x, y, 3);
	}
	else if (except_dir == 1) {
		watch(x, y, 0);
		watch(x, y, 2);
		watch(x, y, 3);
	}
	else if (except_dir == 2) {
		watch(x, y, 1);
		watch(x, y, 0);
		watch(x, y, 3);
	}
	else if (except_dir == 3) {
		watch(x, y, 1);
		watch(x, y, 2);
		watch(x, y, 0);
	}

}
void five(int x, int y) {
	watch(x, y, 0);
	watch(x, y, 1);
	watch(x, y, 2);
	watch(x, y, 3);
}




int watched[10][10] = { {0,} };
int map[10][10] = { {0,} };
int main() {
	int n, m;
	cin >> n >> m;
	int area = 0;
	int answer = n * m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (watched[i][j] == 0)area++;
		}
	}
	answer = min(answer, area);
}




#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // ����, ����, ����, ���� ����
int n, m;
int board1[10][10]; // ���ʿ� �Է¹��� board�� ������ ����
int board2[10][10]; // �簢 ������ ������ ���� ���� ����� ����
vector<pair<int, int> > cctv; // cctv�� ��ǥ�� ������ ����

bool OOB(int a, int b) { // Out Of Bounds Ȯ��
	return a < 0 || a >= n || b < 0 || b >= m;
}// �� �Լ� �׻� �������OOB�� ���� �����ϱ�

// (x,y)���� dir �������� �����ϸ鼭 ���� ���� �� ���� ����ġ�� ��� ��ĭ�� 7�� �ٲ����
void upd(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; // ������ ����ų� ���� ������ �Լ��� Ż��
		if (board2[x][y] != 0) continue; // �ش� ĭ�� ��ĭ�� �ƴ� ���(=cctv�� ���� ���) �Ѿ
		board2[x][y] = 7; // ��ĭ�� 7�� ����
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mn = 0; // �簢 ������ �ּ� ũ�� (=��)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
			if (board1[i][j] == 0) mn++;
		}
	}
	// 1 << (2*cctv.size())�� 4�� cctv.size()���� �ǹ�.
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) { // tmp�� 4�������� ���� �� �� �ڸ����� cctv�� �������� ������ ���̴�.
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board2[i][j] = board1[i][j];
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].X;
			int y = cctv[i].Y; // tie(x, y) = cctv[i];�� ���� 1�ٷ� ���� �� ����
			if (board1[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (board1[x][y] == 2) {
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (board1[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else { // board1[x][y] == 5
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val += (board2[i][j] == 0);
		mn = min(mn, val);
	}
	cout << mn;
}