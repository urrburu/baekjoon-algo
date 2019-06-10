#include <iostream>

using namespace std;
int func(int n, int k) {
	if (n < k)return 0;
	if (k == 0)return 1;
	return func(n - 1, k - 1) + func(n - 1, k);
}
int main() {
	int n, k;
	cin >> n >> k;
	cout<<func(n, k);
}