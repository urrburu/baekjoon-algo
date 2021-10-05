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

