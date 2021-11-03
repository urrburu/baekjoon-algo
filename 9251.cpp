#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int DP[1001][1001] = { {0,} };
int main() {
	string a, b;
	cin >> a >> b;
	a = '0' + a;
	b = '0' + b;
	for (int i = 1; i < a.length(); ++i) {
		for (int j = 1; j < b.length(); ++j) {
			DP[i][j] = max({ DP[i - 1][j], DP[i][j - 1], (DP[i - 1][j - 1] + (a[i] == b[j])) });
			//cout << DP[i][j] << " ";
		}
		//cout << "\n";
	}
	cout << DP[a.length() - 1][b.length() - 1] << " \n";
}