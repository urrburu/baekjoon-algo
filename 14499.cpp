#include<iostream>
#include<vector>

using namespace std;

vector<int> dice(7, 0);
vector<int> order;
int x, y;//dice location
int n, m, k;
int map[21][21];

bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }
//오답의 원인. OOB함수를 쓸때 벗어나지 않았다는 의미로 !를 붙여줬어야 했는데 
//그냥 써버림
void east() {//1
	int tmp = dice[1];
	dice[1] = dice[4];
	dice[4] = dice[6];
	dice[6] = dice[3];
	dice[3] = tmp;
	y++;
}
void west() {//2
	int tmp = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = dice[4];
	dice[4] = tmp;
	y--;
}
void north() {//3
	int tmp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = dice[2];
	dice[2] = tmp;
	x--;
}
void south() {//4
	int tmp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = dice[5];
	dice[5] = tmp;
	x++;
}
void copy_dice() {
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
}
int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; ++i) {
		int ord;
		cin >> ord;
		order.push_back(ord);
	}
	for (int i = 0; i < order.size(); ++i) {
		if (order[i] == 1 && !OOB(x, y + 1)) {
			east(); copy_dice();
			cout << dice[1] << '\n';
		}
		if (order[i] == 2 && !OOB(x, y - 1)) {
			west();
			if (map[x][y] != 0) {
				dice[6] = map[x][y];
				map[x][y] = 0;
			}
			else {
				map[x][y] = dice[6];
			}
			cout << dice[1] << '\n';
		}
		if (order[i] == 3 && !OOB(x - 1, y)) {
			north();
			if (map[x][y] != 0) {
				dice[6] = map[x][y];
				map[x][y] = 0;
			}
			else {
				map[x][y] = dice[6];
			}
			cout << dice[1] << '\n';
		}
		if (order[i] == 4 && !OOB(x + 1, y)) {
			south();
			if (map[x][y] != 0) {
				dice[6] = map[x][y];
				map[x][y] = 0;
			}
			else {
				map[x][y] = dice[6];
			}
			cout << dice[1] << '\n';
		}
	}

}
