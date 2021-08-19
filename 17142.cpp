#include<iostream>
#include<algorithm>
#include<tuple>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n;
int map[55][55];
int scatt[55][55];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int, int>> virus;
int m;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
int count() {
	int step = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] != 1 && scatt[i][j] == -1)return 987654321;
			if (map[i][j] == 0) {
				step = max(scatt[i][j], step);
			}

		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << scatt[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << step << "\n\n";*/
	return step;
}
int main() {
	cin >> n >> m;
	int ans = 987654321;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });

			}
		}
	}
	vector<bool> sel(virus.size(), false);
	fill(sel.end() - m, sel.end(), true);
	do {
		queue<pair<int, int>> q;
		memset(scatt, -1, sizeof(scatt));
		for (int i = 0; i < sel.size(); ++i) {
			if (sel[i] == true) {
				q.push(virus[i]);
				scatt[virus[i].first][virus[i].second] = 0;
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!OOB(nx, ny) && scatt[nx][ny] == -1 && map[nx][ny] != 1) {
					q.push({ nx,ny });
					//cout << nx << " " << ny << " \n";
					scatt[nx][ny] = scatt[x][y] + 1;




					/*for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							cout << scatt[i][j] << " ";
						}
						cout << "\n";
					}
					cout << "\n";*/
				}
			}
		}
		int step = count();

		ans = min(ans, step);
	} while (next_permutation(sel.begin(), sel.end()));
	if (ans == 987654321) { cout << -1 << "\n"; return 0; }
	cout << ans << "\n";
}
//
//���� ������ �ʿ�� ���ٴ� ���� ����� ��. 
//���� ���̷����� ������ ĭ�� �����Ѵٰ� �Ҷ�, ���⸦ �������� ������ 
//������ �������� ���Ե�����
//���� �����Ǿ��ִ� ĭ�̹Ƿ� ������Ű�µ� �󸶰� �ɸ���
//���´ٸ� �ð��� �ɸ��� �ʴ´ٰ� �����
//�׷��Ƿ� ��Ȱ�� ���̷��� ĭ�� ī��Ʈ���� ������ 
//�� ���� ĳġ�Ѵٸ� Ǯ �� �ִ� ����. 
//���Ҿ� memset�� fill �Լ��� ���ؼ��� �ٽ� ���ΰ� �ʿ�