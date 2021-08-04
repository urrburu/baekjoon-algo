#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int n;
int s;
int answer = 987654321;
int main() {

	cin >> n >> s;
	vector<int> list(n);
	for (int i = 0; i < n; ++i) {
		cin >> list[i];
	}
	int left = 0; int right = 0; int sum = list[0];
	while (left <= right && right < n) {
		if (sum < s) {
			right += 1;
			sum += list[right];
		}
		else if (sum == s) {
			answer = min(answer, right - left + 1);
			right += 1;
			sum += list[right];
		}
		else if (sum > s) {
			if (right - left + 1 < answer) {
				answer = right - left + 1;
			}
			sum -= list[left];
			left += 1;


		}
	}
	if (answer == 987654321) {
		cout << 0 << '\n';
		return 0;
	}
	cout << answer << '\n';
	return 0;
}
/*
�� �������� "�̻�"�κа� left�ε��� �κ��� �߸� ó���ߴ� �����̸鼭 

���ÿ� ������ left�� ���������� ����, ������ S�̻��϶��� �߸� �����ѹ���

ū �˰����� �¾����� ������ �� ������, ������ ������ �Ĳ��� �Ұ�.
*/