#include<iostream>
#include<algorithm>

using namespace std;
int m, n;
int Board[101][101];
void Reverse(int x, int y) {
	for (int i = 0; i <= x; ++i) {

		for (int j = 0; j <= y; ++j) {
			Board[i][j] = 1 - Board[i][j];
		}
	}
}
int main() {
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			Board[i][j] = s[j] - '0';
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (Board[i][j] == 1) {
				cnt++; Reverse(i, j);
			}
		}
	}
	cout << cnt << "\n";
}