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
}//솔브한 코드. 하지만 문제의 입력값은 삼십만인데
//이만만 값이 입력되어도 터져버림.... 어째야하나.....

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

//처음에 짰다가 틀린 오답코드. 무턱대고 그리디하게 풀었다. 40같은 케이스에서는 
//20+20 이 아니라 35+4+1의 오류가 날 것임을 알 수 있다. 

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
}//바킹독 코드. 잘짜는 사람은 다르다......
//나는 탑다운 방식으로 갔는데 
//바텀업으로 빌드해서 도달할 줄은 몰랐다.....