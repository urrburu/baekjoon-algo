#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int board[21][21];
int board_store[21][21];
int n;
void rotate() {
	int copy_board[21][21];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			copy_board[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			board[i][j] = copy_board[n - 1 - j][i];
		}
	}

}
void left_wipe(int dir) {
	for (int i = 0; i < dir; ++i)rotate();
	for (int i = 0; i < n; ++i) {
		int wipe[21] = { 0, };
		int index = 0;
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 0)continue;
			if (wipe[index] == 0) {
				wipe[index] = board[i][j];
			}
			else if (wipe[index] == board[i][j]) {
				wipe[index++] *= 2;
			}
			else {
				wipe[++index] = board[i][j];
			}
		}
		for (int j = 0; j < n; ++j) {
			board[i][j] = wipe[j];
		}
	}
	for (int i = 0; i < (4 - dir) % 4; ++i)rotate();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board_store[i][j];
		}
	}
	//1=down, 2=right 3=up
	int max_num = 0;
	for (int tmp = 0; tmp < 1024; ++tmp) {
		int dir_col = tmp;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				board[i][j] = board_store[i][j];
			}
		}
		for (int k = 0; k < 5; ++k) {
			int dir = dir_col % 4;
			dir_col /= 4;

			left_wipe(dir);

			//cout << dir << " ";
		}
		//cout << "\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				//cout << board[i][j] << " ";
				max_num = max(max_num, board[i][j]);
			}
			//cout << "\n";
		}
		//cout << "\n";
	}
	cout << max_num << "\n";
}