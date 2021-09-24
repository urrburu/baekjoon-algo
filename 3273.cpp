#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, x;

int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	cin >> x;
	sort(v.begin(), v.end());
	int ans = 0;
	int begin = 0; int end = n - 1;
	while (begin < end) {
		int sum = v[begin] + v[end];
		if (sum < x) {
			begin++;
		}
		else if (sum == x) {
			ans++; begin++;
		}
		else if (sum > x) {
			end--;
		}
	}
	cout << ans << "\n";
}//클린 AC 한번에 짜서 맞춤