#include<iostream>
#include<vector>

using namespace std;
int board[2200][2200];
int answer[3];
bool check(int start_x, int start_y, int end_x, int end_y) {
	int tmp = board[start_x][start_y];
	for (int i = start_x; i < end_x; ++i) {
		for (int j = start_y; j < end_y; ++j) {
			if (tmp != board[i][j])return false;
		}
	}
	return true;
}

int n;

void divide(int row, int col, int num) {
	if (check(row, col, row + num, col + num)) {
		answer[board[row][col] + 1]++;
	}
	else {
		int size = num / 3;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				divide(row + size * i, col + size * j, size);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
}
//문제 : 문제에서 뭘 묻고 있는지 제대로 파악이 안됨. 
//메인과 체크는 만들었는데 핵심인 디바이드를 못만듬
//if의 브레이크부분과 따라오는 엑셀부분을 잘 고려해서 짰어야함. 