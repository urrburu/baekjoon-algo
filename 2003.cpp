#include<iostream>
#include<vector>
using namespace std;
int n, m;

int main() {
	cin >> n >> m;
	int answer = 0;
	vector<int> list(n);
	for (int i = 0; i < n; ++i) {
		cin >> list[i];
	}
	int index1 = 0, index2 = 0;
	int sum = list[0];
	while (index2 <= index1 && index1 < n) {
		if (sum < m) { index1 += 1;  sum += list[index1]; }
		else if (sum == m) { answer++; index1 += 1; sum += list[index1]; }
		else if (sum > m) {
			sum -= list[index2]; index2++;
			if (index2 > index1 && index2 < n) { index1 = index2; sum = list[index2]; }
		}
	}
	cout << answer << '\n';
	return 0;
}