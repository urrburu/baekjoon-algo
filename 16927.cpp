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
		//�� �κ��� ó���ϴ� �� �����̾���. �̰ɷ� 4�� Ʋ��, 
		//������ ������ �Ĳ��� ���ϰ� �ϰ��� ó���� ���ַ��� �� ��, ��Ȯ�ϰ� ���������� ��Ƴ� �� �־��µ� �� ��Ƴ� ���̴�. 
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