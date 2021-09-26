#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int n, m;
int board[16][16];
int board_copy[16][16];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
void move() {
	int board2[16][16];
	for (int i = 0; i < m; ++i) {
		board2[0][i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			board2[i + 1][j] = board[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			board[i][j] = board2[i][j];
		}
	}
}
pair<int, int> bfs(int j, int d) {
	vector<tuple<int, int, int> > kill;
	queue<tuple<int, int, int> > q;
	int visit[16][16];
	memset(visit, -1, sizeof(visit));
	q.push(make_tuple(n, j, 0));
	visit[n][j] = 0;
	while (!q.empty()) {
		int x, y, dist;
		tie(x, y, dist) = q.front(); q.pop();
		if (board[x][y] == 1) { kill.push_back(make_tuple(dist, y, x)); }
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (!OOB(nx, ny) && visit[nx][ny] == -1 && dist < d) {
				q.push(make_tuple(nx, ny, dist + 1));
				visit[nx][ny] = dist + 1;
			}
		}
	}
	if (kill.empty())return { -1,-1 };
	sort(kill.begin(), kill.end());
	int rx, ry, rdist;
	tie(rdist, ry, rx) = kill[0];
	return { rx,ry };
}
bool check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1)return true;
		}
	}
	return false;
}
int main() {
	int d;
	int max_num = 0;
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board_copy[i][j];
		}
	}
	vector<bool> choice(m, false);
	fill(choice.end() - 3, choice.end(), true);
	do {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[i][j] = board_copy[i][j];
			}
		}
		int answer = 0;
		vector<int> arch;
		for (int ch = 0; ch < m; ++ch) {
			if (choice[ch] == true) { arch.push_back(ch); }
		}
		while (check()) {
			set<pair<int, int> > kill;
			for (int i = 0; i < 3; ++i) {
				pair<int, int> loc = bfs(arch[i], d);
				//cout << arch[i] << " ";
				//cout << loc.first << " " << loc.second << " \n";
				if (loc.first != -1)kill.insert(loc);
			}
			for (auto it : kill) {
				board[it.first][it.second] = 0; answer++;

			}
			move();
		}
		//cout << answer << "\n";
		max_num = max(max_num, answer);
	} while (next_permutation(choice.begin(), choice.end()));
	cout << max_num << "\n";
}//솔브. 만약 퍼뮤테이션을 돌려서 아처의 위치를 세팅해줄때
//게임판도 같이 새로 세팅해줘야한다는 점을 깜빡함
//그래서 시간을 잡아먹음. 