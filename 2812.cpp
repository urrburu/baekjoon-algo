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
	//n�� �߿� �ݵ�� k���� ��������߸� �ϱ� ������ 
	//�� �κ��� �ʿ��ߴ�. ó���� ������� �ʾƼ� Ʋ�ȴ�. 
	//��� ����ؾ��ϳ� �� �������̽��� ����ؾ߸� �Ѵ�. 
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
//�ٸ� ���� ����ڵ�. ������ ���� �ʰ� ���� ȿ���� �� �� �ְ� �����ߴ�. 
//������ ������, �����ϴ� ���μ����� �� ���� ���� ����.