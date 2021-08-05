void Solution() {
	deque<pair<int, int>> q;
	int x = 0, y = 0, d = 0;
	int time = 0, idx = 0;
	q.push_back(make_pair(x, y));
	map[x][y] = 2;

	while (1) {
		time++;

		int nx = x + dx[d];
		int ny = y + dy[d];
		if ((nx < 0 || ny < 0 || nx >= n || ny >= n) || map[nx][ny] == 2) {
			break;
		}
		else if (map[nx][ny] == 0) {
			map[nx][ny] = 2;
			map[q.back().first][q.back().second] = 0;
			q.pop_back();
			q.push_front(make_pair(nx, ny));
		}
		else if (map[nx][ny] == 1) {
			map[nx][ny] = 2;
			q.push_front(make_pair(nx, ny));
		}

		if (idx < moving.size()) {
			if (time == moving[idx].first)
			{
				if (moving[idx].second == 'L') d = Turn_Direction(d, 'L');
				else if (moving[idx].second == 'D') d = Turn_Direction(d, 'D');
				idx++;
			}
		}
		x = nx;
		y = ny;
	}
	cout << time << endl;
}

#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dir = 0;
int n;
int map[101][101];
void change_dir(char turn) {
	if (turn == 'D') {
		dir += 1;
		dir %= 4;
	}
	else if (turn == 'L') {
		if (dir == 0) { dir = 3; }
		else { --dir; }
	}
}
bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}
int main() {
	int k, l;
	vector<pair<int, char>> move;
	deque<pair<int, int>> snake;

	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}
	cin >> l;
	while (l--) {
		int sec;
		char d;
		cin >> sec >> d;
		move.push_back({ sec,d });
	}
	snake.push_front({ 0, 0 });
	map[0][0] = 2;
	int index = 0;
	int time = 0;

	while (1) {
		time++;
		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];
		if (OOB(nx, ny) || map[nx][ny] == 2) {
			cout << time << '\n';
			return 0;
		}
		else if (map[nx][ny] == 0) {
			map[snake.back().first][snake.back().second] = 0;
			map[nx][ny] = 2;
			//cout << nx << " " << ny <<" "<< dir<< " \n";
			snake.pop_back();
			snake.push_front({ nx,ny });
		}
		else if (map[nx][ny] == 1) {
			snake.push_front({ nx,ny });
			//cout << nx << " " << ny <<" "<< dir<<" \n";
			map[nx][ny] = 2;
		}
		if (index < move.size() && time == move[index].first) {
			change_dir(move[index].second);
			index++;
		}
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
	}
}