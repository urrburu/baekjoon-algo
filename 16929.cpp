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

//���� 90���� Ǯ�� �������� ����Ŭ �κп��� �Ǽ�. 
//����Ŭ �Ÿ��� �󸶰� �ȴٴ°� ��Ƴ��� ���ϰ�
//�ѹ� �湮�ߴ� ��带 �ٽ� �湮�ؼ� ���� 2¥�� ����Ŭ�� 
//ó���� true�� ���͹���
//���� �湮������ ����ϰų� ������������ ����Ŭ�� �Ÿ��� �󸶳� �Ǵ���
//����ϴ� ���������� ���� Ȯ���Ұ�.