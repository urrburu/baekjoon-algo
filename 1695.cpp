#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n;
int Inside[5001][5001];
vector<int> VEC;
int Dfs(int start, int end) {
	if (start == end || start > end)return 0;
	if (Inside[start][end] != -1)return Inside[start][end];
	Inside[start][end] = 0;
	if (VEC[start] == VEC[end]) {
		Inside[start][end] += Dfs(start + 1, end - 1);
	}
	else {
		Inside[start][end] += min(Dfs(start, end - 1) + 1, Dfs(start + 1, end) + 1);
	}
	return Inside[start][end];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) { int a; cin >> a; VEC.push_back(a); }
	memset(Inside, -1, sizeof(Inside));
	cout << Dfs(0, n - 1) << "\n";
}