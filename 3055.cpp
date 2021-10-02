#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
char Map[51][51];
int marked[51][51];
int r, c;
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= r || y >= c; }
void prev_bfs(vector<pair<int, int>>& water) {
	memset(marked, 98765432, sizeof(marked));
	bool visit[51][51] = { false, };
	queue<pair<int, int> > q;
	for (int i = 0; i < water.size(); ++i) {
		q.push({ water[i].first, water[i].second });
		marked[water[i].first][water[i].second] = 0;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (!OOB(nx, ny) && marked[nx][ny] > marked[x][y] + 1 && Map[nx][ny] == '.' && visit[nx][ny] == false) {
				marked[nx][ny] = marked[x][y] + 1;
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
int bfs(int start_x, int start_y, int dest_x, int dest_y) {
	bool visit[51][51] = { false, };
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(start_x, start_y, 0));
	visit[start_x][start_y] = true;
	while (!q.empty()) {
		int x, y, step; tie(x, y, step) = q.front(); q.pop();
		if (x == dest_x && y == dest_y)return step;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (!OOB(nx, ny) && (Map[nx][ny] == '.' || Map[nx][ny] == 'D') && marked[nx][ny] > step + 1 && visit[nx][ny] == false) {
				//여기에서 도착점은 물에 잠기지 않는다는 조건을 깜빡했다. 
				q.push(make_tuple(nx, ny, step + 1));
				//cout << nx << " " << ny << " "<<step+1<<"\n";

				visit[nx][ny] = true;
			}
		}
	}
	return -1;
}
int main() {
	cin >> r >> c;
	vector<pair<int, int > > water;
	int start_x, start_y;
	int dest_x, dest_y;
	for (int i = 0; i < r; ++i) {
		string s; cin >> s;
		for (int j = 0; j < c; ++j) {
			Map[i][j] = s[j];
			if (Map[i][j] == 'D') { dest_x = i; dest_y = j; }
			if (Map[i][j] == 'S') { start_x = i; start_y = j; Map[i][j] = '.'; }
			if (Map[i][j] == '*') { water.push_back({ i,j }); Map[i][j] = '.'; }
		}
	}
	prev_bfs(water);


	/*for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << marked[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	int result = bfs(start_x, start_y, dest_x, dest_y);
	if (result == -1) {
		cout << "KAKTUS" << "\n"; return 0;
	}
	cout << result << "\n";
}