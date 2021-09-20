#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
int board[11][11];
bool isused[11][11];
int ans = -987654321;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void go(int px, int py, int cnt, int sum) {
	if (cnt == k) { ans = (sum > ans) ? sum : ans; return; }
	else {
		for (int i = px; i < n; ++i) {
			for (int j = (i == px ? py : 0); j < m; ++j) {
				if (isused[i][j] == true)continue;
				bool ok = true;
				for (int iter = 0; iter < 4; ++iter) {
					int nx = i + dx[iter]; int ny = j + dy[iter];
					if (!OOB(nx, ny) && isused[nx][ny] == true) {
						ok = false;
					}
				}
				if (ok == true) {
					isused[i][j] = true;
					go(i, j, cnt + 1, sum + board[i][j]);
					isused[i][j] = false;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			isused[i][j] = false;
		}
	}
	go(0, 0, 0, 0);
	cout << ans << "\n";
}//�����ڵ�. 


#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
int board[11][11];
bool isused[11][11];
int ans = -987654321;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void go(int cnt, int sum) {
	if (cnt == k) { ans = (sum > ans) ? sum : ans;	return; }
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (isused[i][j] == true)continue;
				isused[i][j] = true;
				for (int iter = 0; iter < 4; ++iter) {
					int nx = i + dx[iter]; int ny = j + dy[iter];
					if (!OOB(nx, ny))isused[nx][ny] = true;
				}
				go(cnt + 1, sum + board[i][j]);
				isused[i][j] = false;
				for (int iter = 0; iter < 4; ++iter) {
					int nx = i + dx[iter]; int ny = j + dy[iter];
					if (!OOB(nx, ny))isused[nx][ny] = false;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			isused[i][j] = false;
		}
	}
	go(0, 0);
	cout << ans << "\n";
}// �ʱ� �����ڵ�. �� �߸������ �����ؼ� �ڵ带 �ٽúô�. 
//����� ���� ��ó�� �ִٴ� ������ ���� �� ���� ���� �� ��ó�� 
//�ִٴ� ������ ���� �ٸ� ���̴�. �ű⿡ �߰���
//�ٽ� ������� �ʾҴٴ� ������ �ǵ����ָ鼭 ������ ������ �ְ��� �߻��ߴ�. 
//���� 1,1�� 1,3�� ���ٴ� �������� ���� �ǹ̸� ���Ѵ�. 
//������ ���� Ž������ 1,3�� 1,4�� �������� �ٲ�� 0,3, 1,2, 2,3, 1,4�� 
//����ߴٴ� �������� ��������. ������ 1,2�� ��� ����� �� ������ �� ���� 
//�ְ�ȴ�. �ᱹ �����Ҷ����� Ȯ���� ���� Ž���� �ִ� ���� �� Ȯ���� ������ 
//�����Ѵ�. 