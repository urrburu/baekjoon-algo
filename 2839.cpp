#include <iostream>
using namespace std;
int main() {
	int n = 0;
	int three = 0, five = 0;
	int ans = 0;
	cin >> n;
	if (n % 3 == 1) {
		if (n >= 10) {
			five = 2;
			three = (n - 10) / 3;
		}
		else { ans = -1; }
	}
	else if (n % 3 == 2) {
		if (n >= 5) {
			five = 1;
			three = (n - 5) / 3;
		}
		else { ans = -1; }
	}
	else {
		three = n / 3;
	}

	if (three >= 5) {
		five += (three / 5) * 3;
		three = three - (three / 5) * 5;
	}
	if (ans != -1) {
		cout << three + five << endl;
	}
	else { cout << ans << endl; }
	return 0;
}