#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int max_n = -987654321;
int min_n = 987654321;
int arr[12];
void dfs(int result, int index, int plus, int minus, int multi, int div) {
	if (index == n) {
		max_n = max(max_n, result);
		min_n = min(min_n, result);
		return;
	}
	if (plus > 0) {
		dfs(result + arr[index], index + 1, plus - 1, minus, multi, div);
	}
	if (minus > 0) {
		dfs(result - arr[index], index + 1, plus, minus - 1, multi, div);
	}
	if (multi > 0) {
		dfs(result * arr[index], index + 1, plus, minus, multi - 1, div);
	}
	if (div > 0) {
		dfs(result / arr[index], index + 1, plus, minus, multi, div - 1);
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int plus, minus, multi, div;
	cin >> plus >> minus >> multi >> div;
	dfs(arr[0], 1, plus, minus, multi, div);
	cout << max_n << '\n' << min_n << "\n";
}