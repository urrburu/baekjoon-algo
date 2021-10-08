#include<iostream>
#include<vector>
using namespace std;
int n;
int ans = 0;
void dfs(vector<int>& ball, int sum) {
	if (ball.size() == 2) {
		if (sum > ans)ans = sum;
		return;
	}
	for (int i = 1; i < ball.size() - 1; ++i) {
		vector<int> Nball = ball; Nball.erase(Nball.begin() + i);
		int Addon = ball[i - 1] * ball[i + 1];
		dfs(Nball, sum + Addon);
	}
}
int main() {
	cin >> n;
	vector<int> Energy(n);
	for (int i = 0; i < n; ++i)cin >> Energy[i];
	dfs(Energy, 0);
	cout << ans << "\n";
}
