#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int board[101][101];
long long visit[101][101];
int n;
void dfs(int x, int y) {
    int temp = board[x][y];
    if (x == n - 1 && y == n - 1) { return; }
    if (x + temp < n) {
        visit[x + temp][y] += visit[x][y];
    }
    if (y + temp < n) {
        visit[x][y + temp] += visit[x][y];
    }
}

int main() {
    cin >> n;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            visit[i][j] = 0;
        }
    }
    visit[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dfs(i, j);
        }
    }
    cout << visit[n - 1][n - 1] << "\n";
}
