#include<iostream>
#include<vector>
using namespace std;
int board[10][10];
vector<pair<int, int> > tar;
bool found = false;
bool check(int x, int y) {
	int xx = (x / 3) * 3;
	int yy = (y / 3) * 3;
	int square_count[10] = { 0, };
	int row_count[10] = { 0, };
	int col_count[10] = { 0, };
	for (int i = xx; i < xx + 3; ++i) {
		for (int j = yy; j < yy + 3; ++j) {
			square_count[board[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; ++i) { if (square_count[i] > 1)return false; }
	for (int i = 0; i < 9; ++i) { row_count[board[i][y]]++; }
	for (int i = 1; i <= 9; ++i) { if (row_count[i] > 1)return false; }
	for (int i = 0; i < 9; ++i) { col_count[board[x][i]]++; }
	for (int i = 1; i <= 9; ++i) { if (col_count[i] > 1)return false; }
	return true;
}
void dfs(int index) {
	if (index == tar.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		found = true;
		return;
	}
	for (int Input = 1; Input < 10; ++Input) {
		board[tar[index].first][tar[index].second] = Input;
		if (check(tar[index].first, tar[index].second)) {
			//cout << index + 1 << " "<< board[tar[index].first][tar[index].second]<<"\n";
			dfs(index + 1);
			if (found)return;
		}
	}
	board[tar[index].first][tar[index].second] = 0;
	//�� �κ��� ���� �߿��ߴ�. ���� �� ������༭ Ʋ��.
	return;
}
int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0) { tar.push_back({ i,j }); }
		}
	}
	dfs(0);
}

#include<iostream>
#include<vector>
using namespace std;

int Sdoku[10][10];
bool Complete = false;
vector<pair<int, int>> Blank;
bool Check(int x, int y, int num) {
	int px = ((x - 1) / 3) * 3; int py = ((y - 1) / 3) * 3;
	for (int i = px + 1; i < px + 4; ++i) {
		for (int j = py + 1; j < py + 4; ++j) {
			if (Sdoku[i][j] == num)return false;
		}
	}
	for (int i = 1; i < 10; ++i) {
		if (Sdoku[i][y] == num)return false;
		if (Sdoku[x][i] == num)return false;
	}
	return true;
}

void dfs(int number) {
	if (number == Blank.size()) { Complete = true; return; }
	int tx = Blank[number].first;
	int ty = Blank[number].second;
	for (int target_num = 1; target_num < 10; ++target_num) {
		if (Check(tx, ty, target_num) == true) {
			Sdoku[tx][ty] = target_num;
			dfs(number + 1);
			if (Complete == true)return;
			else {
				Sdoku[tx][ty] = 0;
			}
		}
	}

}
int main() {
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			cin >> Sdoku[i][j];
			if (Sdoku[i][j] == 0) { Blank.push_back({ i,j }); }
		}
	}
	dfs(0);
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			cout << Sdoku[i][j] << " ";
		}
		cout << "\n";
	}
}