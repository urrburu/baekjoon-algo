#include    <iostream>
#include    <algorithm>
using namespace std;
int T[55555];
int D[4][55555];
int main()
{
    int N, M;
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int tmp;
        cin >> tmp;
        T[i] = T[i - 1] + tmp;
    }
    cin >> M;

    for (int i = 1; i <= 3; ++i)
        for (int j = i * M; j <= N; ++j)
            D[i][j] = max(D[i][j - 1], (T[j] - T[j - M]) + D[i - 1][j - M]);

    cout << D[3][N];
    return 0;
}
// DP¹®Á¦´Ù.

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n = 0, k = 0;
int dp[50001][3] = { 0, };
int arr[50001] = { 0, };

int solved(int current, int cnt) {

	if (current > n || cnt == 3)
		return 0;

	int& ret = dp[current][cnt];
	if (ret != -1)
		return ret;

	if ((current + k - 1) <= n)
		ret = max(solved(current + 1, cnt), solved(current + k, cnt + 1) + (arr[current + k - 1] - arr[current - 1]));


	return ret;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}
	cin >> k;
	memset(dp, -1, sizeof(dp));
	cout << solved(1, 0) << endl;

	/*
	for (int i = 1; i <= n; i++)
		cout << arr[i] << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}*/
	return 0;
}