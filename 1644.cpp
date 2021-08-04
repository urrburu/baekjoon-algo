#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define MAX 4000000
using namespace std;
int n;
int s;
int answer = 0;
bool prime[MAX + 1] = { false, };
int main() {

	cin >> s;
	vector<int> num;
	for (int i = 2; i * i <= MAX; ++i) {
		for (int j = i + i; j <= MAX; j += i) {
			prime[j] = true;
		}
	}
	for (int i = 2; i <= MAX; ++i) {
		if (prime[i] == false) {
			num.push_back(i);
		}
	}

	int leng = num.size();
	int left = 0; int right = 0; int sum = num[0];
	while (left <= right && right < leng) {
		if (sum < s) {
			right++;
			sum += num[right];
		}
		if (sum == s) {
			answer++;
			right++;
			sum += num[right];
		}
		if (sum > s) {
			sum -= num[left];
			left++;
			if (left > right)break;
		}
	}
	cout << answer << "\n";
	return 0;
}
