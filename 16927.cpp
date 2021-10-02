#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int board[301][301];
int n, m, r;
int gcd(int a, int b) {
	if (b > a) { int tmp = b; b = a; a = tmp; }
	if (a % b)return gcd(b, a % b);
	else return b;
}
void rotate_line(int start_x, int start_y) {
	int tmp = board[start_x][start_y];
	for (int i = start_y; i < m - 1 - start_y; ++i) {
		board[start_x][i] = board[start_x][i + 1];
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = start_x; i < n - 1 - start_x; ++i) {
		board[i][m - 1 - start_y] = board[i + 1][m - 1 - start_y];
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = m - 1 - start_y; i > start_y; --i) {
		board[n - 1 - start_x][i] = board[n - 1 - start_x][i - 1];
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = n - 1 - start_x; i > start_x; --i) {
		board[i][start_y] = board[i - 1][start_y];
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}*/
	board[start_x + 1][start_y] = tmp;
}
void rotate(int num) {
	int rep = min(m / 2, n / 2);
	for (int i = 0; i < rep; ++i) {
		int tmp = (n + m) * 2 - 4 - (8 * i);
		cout << tmp << "\n";
		tmp = num % tmp;
		//이 부분을 처리하는 게 관건이었다. 이걸로 4번 틀림, 
		//원인은 생각을 꼼꼼히 안하고 일괄로 처리를 해주려고 한 것, 정확하게 접근했으면 잡아낼 수 있었는데 못 잡아낸 것이다. 
		while (tmp--) { rotate_line(i, i); }
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}*/
	}

}
int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}
	rotate(r);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}