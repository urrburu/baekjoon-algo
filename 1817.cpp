#include<iostream>
#include<vector>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	vector<int> vec(n, 0);
	for (int i = 0; i < n; ++i) { cin >> vec[i]; }
	if (n == 0) { cout << 0 << "\n"; return 0; }
	int ans = 1; int last = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (last + vec[i] > m) {
			ans++; last = vec[i];
		}
		else {
			last += vec[i];
		}
	}
	cout << ans << "\n";
}