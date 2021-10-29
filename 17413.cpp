#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s; getline(cin, s);
	bool TagOn = false;
	int index = 0;
	string ans = "";
	for (int i = 0; i < s.length(); ++i) {
		if (TagOn && s[i] != '>')continue;
		if (s[i] == '>') {
			TagOn = false;
			ans += s.substr(index, i - index + 1);
			index = i + 1;
		}
		if (s[i] == '<') {
			TagOn = true;
			string SubStr = s.substr(index, i - index);
			reverse(SubStr.begin(), SubStr.end());
			ans += SubStr; index = i;
		}
		if (s[i] == ' ') {
			string SubStr = s.substr(index, i - index);
			reverse(SubStr.begin(), SubStr.end());
			ans += SubStr; ans += " "; index = i + 1;
		}
		else if (i == s.length() - 1 && s[i] != '>') {
			string SubStr = s.substr(index, i - index + 1);
			reverse(SubStr.begin(), SubStr.end());
			ans += SubStr;
		}
	}
	cout << ans << " \n";
}