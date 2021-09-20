#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main() {

	string s1; string s2;
	cin >> s1 >> s2;

	int ans = 0;

	vector<vector<int>> vec(s1.length() + 1, vector<int>(s2.length() + 1, 0));

	for (int i = 1; i <= s1.length(); ++i) {
		for (int j = 1; j <= s2.length(); ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				vec[i][j] = vec[i - 1][j - 1] + 1;
				ans = max(ans, vec[i][j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
//코드에서 가장 중요한 부분은 이 위치에서 같은 글자가 발견된다면, 
//이전까지 같은 부분에서 길이가 1 추가되는 개념이다.
// 가장 긴 길이를 구하는 다이나믹 프로그래밍의 방법