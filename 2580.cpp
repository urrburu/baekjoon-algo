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
	//이 부분이 제일 중요했다. 여길 안 만들어줘서 틀림.
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