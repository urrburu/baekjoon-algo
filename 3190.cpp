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

while (1) {
	time++;




}