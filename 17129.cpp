#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
char island[3001][3001];
int visit[3001][3001];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int bfs(int x, int y) {
	memset(visit, -1, sizeof(visit));
	queue < pair<int, int> > q;
	vector<int > answer;
	q.push({ x,y });
	visit[x][y] = 0;
	while (!q.empty()) {
		int cx = q.front().first; int cy = q.front().second; q.pop();
		if (island[cx][cy] != '0') { answer.push_back({ visit[cx][cy] }); }
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i]; int ny = cy + dy[i];
			if (!OOB(nx, ny) && island[nx][ny] != '1' && visit[nx][ny] == -1) {
				q.push({ nx,ny }); visit[nx][ny] = visit[cx][cy] + 1;
				//cout << nx << ny << "\n";
				//for (int i = 0; i < n; ++i) {

				//	for (int j = 0; j < m; ++j) {
				//		cout << visit[i][j] << " ";
				//	}
				//	cout << "\n";
				//}
				cout << "\n";
			}
		}
	}
	if (answer.empty())return -1;
	sort(answer.begin(), answer.end());
	return answer[0];

}
int main() {
	cin >> n >> m;
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			island[i][j] = s[j];
			if (island[i][j] == '2') {
				x = i; y = j; island[i][j] = '0';
			}
		}
	}
	int result = bfs(x, y);

	if (result != -1) {
		cout << "TAK" << "\n" << result; return 0;
	}
	cout << "NIE" << "\n";
}// 중간에 틀린 이유. OOB 함수 설정 하지 않음. 