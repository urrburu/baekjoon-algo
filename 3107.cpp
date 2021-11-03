#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s; cin >> s;
	if (s[0] == ':') { s = "0000" + s; }
	if (s[s.length() - 1] == ':') { s += "0000"; }
	//cout << s << " \n";
	vector<int> Idxs;
	for (int i = 0; i < s.length(); ++i) { if (s[i] == ':')Idxs.push_back(i); }
	//if (Idxs.size() < 7) {
	for (int i = 0; i < Idxs.size() - 1; ++i) {
		if (Idxs[i + 1] - Idxs[i] == 1) {
			int iter = 7 - Idxs.size() + 1;
			s.erase(s.begin() + Idxs[i]);
			while (iter--) {
				s.insert(Idxs[i], ":0000");
			}
		}
	}
	//}
	//cout << s << "\n";
	Idxs.clear();
	for (int i = 0; i < s.length(); ++i) { if (s[i] == ':')Idxs.push_back(i); }

	vector<string> str;
	str.push_back(s.substr(0, Idxs[0]));
	for (int i = 0; i < 6; ++i) {
		str.push_back(s.substr(Idxs[i] + 1, Idxs[i + 1] - Idxs[i] - 1));
	}
	str.push_back(s.substr(Idxs[6] + 1, s.length() - Idxs[6]));
	for (int i = 0; i < str.size(); ++i) {
		//cout << str[i] << " \n";
		if (str[i].length() == 0) { str[i] = "0000" + str[i]; }
		if (str[i].length() == 1) { str[i] = "000" + str[i]; }
		if (str[i].length() == 2) { str[i] = "00" + str[i]; }
		if (str[i].length() == 3) { str[i] = "0" + str[i]; }
	}
	for (int i = 0; i < str.size(); ++i) {
		cout << str[i];
		if (i != str.size() - 1)cout << ":";
	}
}
