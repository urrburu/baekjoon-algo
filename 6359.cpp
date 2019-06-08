#include <iostream>
using namespace std;
int main() {

	int n,r,TC;
	int inp;
	bool hotel[101] = { 0, };//1¿­¸² 0´ÝÈû
	for (int i = 1; i <= 100; ++i) {
		r = i;
		while (r <= 100) {
			if (hotel[r] == true) { hotel[r] = false; }
			else { hotel[r] = true; }
			r += i;
		}
	}
	
	cin >> TC;
	for (int i = 0; i < TC; ++i) {
		cin >> n;
		int ans=0;
		for (int j = 0; j <= n; ++j) {
			ans += hotel[j];
		}
		cout << ans << endl;
	}

	return 0;
}