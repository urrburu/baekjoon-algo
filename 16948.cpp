#include<iostream>
#include<queue>

using namespace std;
int n;
queue<pair<pair<int, int>, int>> q;
int dr[] = { -2,-2,0,0,2,2 };
int cr[] = { -1,1,-2,2,-1,1 };
bool visit[201][201];
bool OOB(int r, int c) { return r < 0 || c < 0 || r >= n || c >= n; }
int main() {
	cin >> n;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	q.push({ {r1,c1},0 });
	visit[r1][c1] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (x == r2 && y == c2) {
			cout << cnt << "\n";
			return 0;
		}
		for (int i = 0; i < 6; ++i) {
			int nx = x + dr[i];
			int ny = y + cr[i];
			if (visit[nx][ny] == false && !OOB())
			{
				q.push({ {nx,ny},cnt + 1 });
				visit[nx][ny] = true;
			}
		}
	}
	cout << -1 << "\n";

}