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
맨 마지막의 "이상"부분과 left인덱스 부분을 잘못 처리했던 문제이면서 

동시에 마지막 left가 뒤집힐때의 조건, 지금의 S이상일때를 잘못 생각한문제

큰 알고리즘은 맞았지만 문제를 잘 읽을것, 논리적인 생각을 꼼꼼히 할것.
*/