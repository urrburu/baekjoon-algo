#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	stack<int> st;
	vector<pair<int, int> > loc;
	set<string> res;
	string s; cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') { st.push(i); }
		if (s[i] == ')') { loc.push_back({ st.top(),i }); st.pop(); }
	}
	for (int i = 1; i <= loc.size(); ++i) {
		vector<bool> che(loc.size(), false);
		fill(che.begin(), che.begin() + i, true);
		do {
			set<int> except;
			for (int k = 0; k < che.size(); ++k) {
				if (che[k] == true) {
					except.insert(loc[k].first);
					except.insert(loc[k].second);
				}
			}
			string ans = "";
			for (int j = 0; j < s.length(); ++j) {
				if (except.find(j) == except.end()) {
					ans += s[j];
				}
			}
			res.insert(ans);
		} while (prev_permutation(che.begin(), che.end()));
	}
	for (string sel : res) {
		cout << sel << "\n";
	}//set으로 중복제거 해주는 작업이 중요함. 근데 안하고 똑같은거 두개 출력
//c*d+((a+b)) 이런식으로 식이 되어있어서 무작정 벡터에 넣고 정렬해줘서 될게 아님. 
}//다음에 재풀이 필요한 문제라고 생각함.