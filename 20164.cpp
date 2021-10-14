#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int ans = 0;
int Sum_two(int op1, int op2) {
	int res = op1 + op2;
	if (res % 2 == 1)ans++;
	return res;
}
int Sum(int op1, int op2, int op3) {
	int res = op1 + op2 + op3;
	if (res % 2 == 1)ans++;
	return res;
}
pair<int, int> dfs(int num) {
	if (num < 10) return { num % 2, num % 2 };
	string temp = to_string(num);
	int cnt = 0;
	for (int i = 0; i < temp.length(); ++i) {
		if ((temp[i] - '0') % 2 == 1)cnt++;
	}
	if (num < 100) {
		return { cnt + dfs(Sum_two(num % 10, num / 10)).first, cnt + dfs(Sum_two(num % 10, num / 10)).second };
	}

	int Max = 0; int Min = 987654321;
	int digit = temp.length();

	vector<bool> Cut(digit - 1, false);
	fill(Cut.end() - 2, Cut.end(), true);
	do {
		vector<int> Idx;
		for (int i = 0; i < Cut.size(); ++i) {
			if (Cut[i] == true)Idx.push_back(i);
		}

		string s1 = temp.substr(0, Idx[0] + 1);
		string s2 = temp.substr(Idx[0] + 1, Idx[1] - Idx[0]);
		string s3 = temp.substr(Idx[1] + 1, temp.length() - Idx[1]);
		//cout << s1 << " " << s2 << " " << s3 << "\n";
		pair<int, int> Res = dfs(Sum(stoi(s1), stoi(s2), stoi(s3)));
		Max = max(Max, Res.first); Min = min(Min, Res.second);

	} while (next_permutation(Cut.begin(), Cut.end()));
	return { Max + cnt, Min + cnt };
}
int main() {
	int n; cin >> n;
	pair<int, int> Result = dfs(n);
	cout << Result.second << " " << Result.first << "\n";
}