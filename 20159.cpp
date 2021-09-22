#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> cards(100001, 0);
long long odd[100005], even[100005];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> cards[i];
		if (i % 2) {
			odd[i] = odd[i - 1] + cards[i];
			even[i] = even[i - 1];
		}
		else {
			odd[i] = odd[i - 1];
			even[i] = even[i - 1] + cards[i];
		}
	}
	long long ans = odd[n];
	for (int i = 1; i < n; ++i) {
		if (i % 2) {
			ans = max(ans, odd[i - 1] + even[n - 1] - even[i] + cards[n]);

		}
		else {
			ans = max(ans, odd[i - 1] + even[n - 1] - even[i - 1]);
		}
	}
	cout << ans;
	//±¸°£ÇÕ, dp, ¿ÏÀüÅ½»öÀ» ÀÌ¿ëÇÏ´Â ¹®Á¦... ÆÄ¾ÇÀÌ Èûµë...
}