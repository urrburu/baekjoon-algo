#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool prime[100001];
int m, k;
bool check1(int n) {
	for (int i = 2; i < n / 2; ++i) {
		if (prime[i] && prime[n - i]) {
			return true;
		}
	}
	return false;
}
bool check2(int n) {
	int num = n;

	while (num % m == 0) {
		num /= m;
	}
	for (int i = 2; i < num / 2; ++i) {
		if (prime[i] && prime[num / i] && num % i == 0) {
			return true;
		}
	}
	return false;
}

int main() {

	cin >> k >> m;
	int ans = 0;
	vector<bool> selc(10, false);
	fill(prime, prime + 100001, true);
	prime[0] = false; prime[1] = false;
	for (int i = 2; i * i < 98765; ++i) {
		for (int j = i + i; j < 99999; j += i) {
			prime[j] = false;
		}
	}
	fill(selc.end() - k, selc.end(), true);
	do {
		vector<int> selected;
		for (int i = 0; i < 10; ++i) {
			if (selc[i] == true)selected.push_back(i);
		}
		do {
			int num = 0;
			for (int i = 0; i < k; ++i) {
				num += selected[i];
				num *= 10;
			}
			num /= 10;
			if (check1(num) && check2(num)) {
				ans++;
				//cout << num<<"\n";
			}
		} while (next_permutation(selected.begin(), selected.end()));
	} while (next_permutation(selc.begin(), selc.end()));
	cout << ans << "\n";

}// 테케는 통과하지만 엣지케이스 해결 못해서 틀림
//풀이 아직 없음
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool prime[100001];
int m, k;
bool check1(int n) {
	for (int i = 2; i < n / 2; ++i) {
		if (prime[i] && prime[n - i]) {
			return true;
		}
	}
	return false;
}
bool check2(int n) {
	int num = n;

	while (num % m == 0) {
		num /= m;
	}
	for (int i = 2; i < num / 2; ++i) {
		if (prime[i] && prime[num / i] && num % i == 0) {
			return true;
		}
	}
	return false;
}

int main() {

	cin >> k >> m;
	int ans = 0;
	vector<bool> selc(10, false);
	fill(prime, prime + 100001, true);
	prime[0] = false; prime[1] = false;
	for (int i = 2; i * i < 98765; ++i) {
		for (int j = i + i; j < 99999; j += i) {
			prime[j] = false;
		}
	}
	fill(selc.end() - k, selc.end(), true);
	do {
		vector<int> selected;
		for (int i = 0; i < 10; ++i) {
			if (selc[i] == true)selected.push_back(i);
		}
		do {
			if (selected[0] == 0)continue;
			int num = 0;
			for (int i = 0; i < k; ++i) {
				num += selected[i];
				num *= 10;
			}
			num /= 10;
			if (check1(num) && check2(num)) {
				ans++;
				//cout << num<<"\n";
			}
		} while (next_permutation(selected.begin(), selected.end()));
	} while (next_permutation(selc.begin(), selc.end()));
	cout << ans << "\n";

}
//솔브 해버렸네?