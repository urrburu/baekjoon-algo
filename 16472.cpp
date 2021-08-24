#include<iostream>
#include<string>

using namespace std;

int main() {
	int ans = 0;
	int num; cin >> num;
	string s; cin >> s;
	int ch[26] = { 0, };
	int left = 0; int right = 0; int count = 0;
	ch[s[0] - 'a'] += 1;
	while (left <= right && left < s.length() - 1) {

		if (count < num) {
			right++;
			if (ch[s[right] - 'a'] == 0)count++;
			ch[s[right] - 'a']++;

		}
		if (count == num) {
			ans = max(ans, right - left - 1);
			right++;
			ch[s[right] - 'a']++;
		}
		if (count > num) {
			ch[s[left] - 'a']--;
			if (ch[s[left] - 'a'] == 0)count--;
			left++;

		}

	}
	cout << ans << "\n";

}//fail code