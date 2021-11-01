#include<iostream>
#include<string>
using namespace std;
int n;
string ans = "";
bool Complete = false;
bool Check(string S) {
	int Stringlength = S.length();
	for (int i = 0; i < Stringlength; ++i) {
		for (int j = 1; i + j + j <= Stringlength; ++j) {
			string part1 = S.substr(i, j);
			string part2 = S.substr(i + j, j);
			if (part1 == part2)return false;
		}
	}
	return true;
}
void Dfs(string S) {
	if (S.length() == n) { ans = S; Complete = true; return; }
	for (char ch = '1'; ch <= '3'; ch++) {
		string newS = S; newS += ch;
		if (Check(newS)) {
			Dfs(newS);
			if (Complete)return;
		}
	}
}
int main() {
	cin >> n;
	Dfs("");
	cout << ans << "\n";

}