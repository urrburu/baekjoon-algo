#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dp[300001] = { 0, };
vector<int> fd;
int dfs(int n) {
	if (dp[n] != 0) return dp[n];
	int ans = 987654321;
	for (int i = 1; fd[i] <= n; ++i) {
		ans = min(ans, dfs(n - fd[i]) + 1);
	}
	dp[n] = ans;
	return ans;
}
int main() {

	vector<int> tri;

	tri.push_back(0); fd.push_back(0);
	for (int i = 1; fd[i - 1] < 300000; ++i) {
		tri.push_back(tri[i - 1] + i);
		fd.push_back(fd[i - 1] + tri[i]);
	}
	for (int i = 1; i < fd.size(); ++i) {
		dp[fd[i]] = 1;
		//cout << fd[i] << " ";
	}
	int n; cin >> n;
	int ans = dfs(n);
	cout << ans << "\n";
}//�ֺ��� �ڵ�. ������ ������ �Է°��� ��ʸ��ε�
//�̸��� ���� �ԷµǾ ��������.... ��°���ϳ�.....

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

	vector<int> tri;
	vector<int> fd;
	tri.push_back(0); fd.push_back(0);
	for (int i = 1; fd[i - 1] < 300000; ++i) {
		tri.push_back(tri[i - 1] + i);
		fd.push_back(fd[i - 1] + tri[i]);
	}
	/*for (int i = 1; i < fd.size(); ++i) {
		cout << fd[i] << " ";
	}*/
	int n; cin >> n;
	int ans = 0;
	while (n) {
		ans++;
		for (int i = fd.size() - 1; i > 0; --i) {
			if (n >= fd[i]) { n -= fd[i]; /*cout << fd[i] << "\n";*/ break; }
		}
	}
	cout << ans << "\n";
}

//ó���� ®�ٰ� Ʋ�� �����ڵ�. ���δ�� �׸����ϰ� Ǯ����. 40���� ���̽������� 
//20+20 �� �ƴ϶� 35+4+1�� ������ �� ������ �� �� �ִ�. 

#include <stdio.h>
#include <algorithm>
using namespace std;
int f(int n) {
	return (2 * n * n * n + 6 * n * n + 4 * n) / 12;
}
int D[300005];
int main(void) {
	int N;
	scanf("%d", &N);
	int i = 1;
	while (f(i) <= N)
		i++;
	for (int i = 0; i <= N; i++)
		D[i] = i;
	for (int i = 2; f(i) <= N; i++)
		for (int j = f(i); j <= N; j++)
			D[j] = min(D[j], D[j - f(i)] + 1);
	printf("%d", D[N]);
}//��ŷ�� �ڵ�. ��¥�� ����� �ٸ���......
//���� ž�ٿ� ������� ���µ� 
//���Ҿ����� �����ؼ� ������ ���� ������.....