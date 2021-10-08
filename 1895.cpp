#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int r, c, t;
int Image[41][41];
int result[39][39];
vector<int> filter(9);
int Mid() { sort(filter.begin(), filter.end()); return filter[4]; }
int main() {
	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> Image[i][j];
		}
	}
	cin >> t;
	int cnt = 0;
	for (int i = 0; i < r - 2; ++i) {
		for (int j = 0; j < c - 2; ++j) {
			for (int it = 0; it < 3; ++it) {
				for (int jt = 0; jt < 3; ++jt) {
					filter[it * 3 + jt] = Image[i + it][j + jt];
				}
			}
			result[i][j] = Mid();
			if (result[i][j] >= t)cnt++;
		}
	}
	cout << cnt << "\n";
}