#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int gap(string& s1, string& s2) {
	int gap = (int)s2.size() - (int)s1.size() + 1;
	int result = 51;
	for (int i = 0; i < gap; ++i) {
		int tmp = 0;
		for (int j = 0; j < s1.size(); ++j) {
			if (s1[j] != s2[j + i])tmp++;
		}
		result = min(result, tmp);
	}
	return result;
}
int main() {
	string a, b;	cin >> a >> b;
	if (a.length() > b.length()) {
		string tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	cout << gap(a, b) << "\n";
	return 0;
}
//�� �����ؾ��Ѵٰ� ���� ����.
//��¥ ��Ű�´�δ� �� �ʿ� ����, �ٽ��� �ľ��ϴ°� �߿��ϴ�.
