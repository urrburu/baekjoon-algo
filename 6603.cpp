#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	do {
		cin >> n;
		if (n == 0)break;
		vector<int> number;
		vector<bool> use(n, 0);
		fill(use.begin(), use.begin() + 6, 1);
		for (int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			number.push_back(temp);
		}
		sort(number.begin(), number.end());
		do {
			for (int i = 0; i < n; ++i) {
				if (use[i] == 1) {
					cout << number[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(use.begin(), use.end()));
		cout << "\n";
	} while (1);
	return 0;
}