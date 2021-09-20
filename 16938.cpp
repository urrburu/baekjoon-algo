#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
int ans = 0;
int main() {
	int L, R, X;
	cin >> n >> L >> R >> X;
	vector<int> question(n);
	for (int i = 0; i < n; ++i)cin >> question[i];
	for (int choice = 2; choice <= n; ++choice) {
		vector<bool> use(n, false);
		fill(use.end() - choice, use.end(), true);
		do {
			int sum = 0; int max_num = -987654321; int min_num = 987654321;
			for (int i = 0; i < n; ++i) {
				if (use[i] == true) {
					sum += question[i];
					if (question[i] > max_num)max_num = question[i];
					if (question[i] < min_num)min_num = question[i];
				}
			}
			if (sum >= L && sum <= R && (max_num - min_num) >= X) {
				ans++;
			}
		} while (next_permutation(use.begin(), use.end()));
	}
	cout << ans << "\n";
}
// 생각하는대로 했더니 풀린 문제. 완전탐색. 바킹독의 순열조합 사용. 