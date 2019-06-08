
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int Dp[301][301] = { 0, };
	int ans = 0;
	for (int i = 1; i < 301; ++i) {
		Dp[1][i] = i - 1;
	}
	for (int i = 2; i < 301; ++i) {
		for (int j = 1; j < 301; ++j) {
			Dp[i][j] = (Dp[1][j] * i) + (i - 1);
		}
	}
	ans = Dp[n][m];
	cout << ans << endl;

	return 0;
}