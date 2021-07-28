#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n, m;
int map[101][101];
bool visit[101][101] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}
int main() {

    queue<pair<pair<int, int>, int>> q;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            map[i][j] = (int)s[j] - 48;
        }
    }
    q.push(make_pair(make_pair(0, 0), 1));
    visit[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << num << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!OOB(nx, ny) && map[nx][ny] == 1 && visit[nx][ny] == false) {
                q.push(make_pair(make_pair(nx, ny), num + 1));
                cout << nx << " " << ny << " " << num + 1 << '\n';
                visit[nx][ny] = true;
            }
        }
    }
}