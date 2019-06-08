#include <iostream>
using namespace std;

int main() {
	int len;
	cin >> len;
	long long Dp[101][10] = { 0, };
	long long ans = 0;
	for (int last = 0; last < 10; ++last) {
		if (last == 0)	Dp[0][last] = 0;
		else { Dp[0][last] =1; }
	}

	for (int i = 1; i < len; ++i) {
		for (int last = 0; last < 10; ++last) {
			if (last == 0)	Dp[i][last] = Dp[i - 1][1];
			else if(last == 9) Dp[i][last] = Dp[i - 1][8];
			else {Dp[i][last] = (Dp[i - 1][last - 1] + Dp[i - 1][last + 1]) % 1000000000;}
		}
	}
	for (int last = 0; last < 10; ++last) {
		ans = (ans + Dp[len - 1][last]) % 1000000000;
	}
	cout << ans << endl;

	return 0;
}