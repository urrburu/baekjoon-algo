#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int n, m;
long long Table[11][2001];

long long dfs(int num, int max) {
	if (Table[num][max] != -1)return Table[num][max];
	int lim = 1;
	for (int i = 1; i < num; ++i) { lim *= 2; }
	long long ret = 0;
	for (int i = lim; i <= max; ++i) {
		ret += dfs(num - 1, i / 2);
	}
	Table[num][max] = ret;
	return ret;
}

int main() {
	memset(Table, -1, sizeof(Table));
	for (long long inp = 1; inp <= 2000; ++inp) { Table[1][inp] = inp; }
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		long long ans = dfs(n, m);
		cout << ans << "\n";
		/*for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << Table[i][j] << " ";
			}
			cout << "\n";
		}*/
	}

}//��ȭ�ĵ�, ���̺� �� ������!
//������ ������ ���� Ÿ���� üũ������ �ʾұ� ������ ó���� Ʋ�ȴ�.