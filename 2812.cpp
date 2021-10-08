#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	stack<int> st;
	int cnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		int num = s[i] - '0';
		while (cnt < k && !st.empty() && st.top() < num) {
			st.pop(); cnt++;
		}
		//cout << num << "\n";
		st.push(num);
	}
	stack<int> ans;
	while (!st.empty()) {
		ans.push(st.top());
		st.pop();
	}
	int c = n - k;
	//n개 중에 반드시 k개를 삭제해줘야만 하기 때문에 
	//이 부분이 필요했다. 처음에 고려하지 않아서 틀렸다. 
	//몇개나 출력해야하나 이 엣지케이스를 고민해야만 한다. 
	while (c--) {
		cout << ans.top();
		ans.pop();
	}
}

#include <iostream>
using namespace std;
char arr[500000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int len, err, tail = 1, tmp;
	cin >> len >> err;
	tmp = err;
	char c;
	cin >> arr[0];
	for (int i = 1; i < len; i++) {
		cin >> c;
		while (err && tail > 0 && arr[tail - 1] < c) {
			tail--;
			err--;
		}
		arr[tail++] = c;
	}
	for (int i = 0; i < len - tmp; i++)
		cout << arr[i];
	return 0;
}
//다른 분의 모범코드. 스택을 쓰지 않고도 스택 효과를 낼 수 있게 구현했다. 
//나쁘진 않은데, 생각하는 프로세스가 더 많이 들어갈거 같다.