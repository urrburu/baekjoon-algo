#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int r, c;
char Board[21][21];
int Maximum = 0;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool visited[26];
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= r || y >= c; }

void dfs(int x, int y, int step) {
	Maximum = max(step, Maximum);
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (!OOB(nx, ny) && visited[Board[nx][ny] - 'A'] == false) {
			visited[Board[nx][ny] - 'A'] = true;
			dfs(nx, ny, step + 1);
			visited[Board[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		string s; cin >> s;
		for (int j = 0; j < c; ++j) {
			Board[i][j] = s[j];
		}
	}
	visited[Board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << Maximum << "\n";
}
//set�� �α�n���� Ž���Ѵٰ� �ص�, �� ��쿡�� 1�� �����ϴ°� �� �̵�
//������ Ž���ؾ��� Ƚ����ü�� �þ�� ���ʰ� �Ͼ ���̽�. 