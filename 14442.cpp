#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, k;
int map[1001][1001] = { {0,} };
bool visit[1001][1001][11];
int ans = 987654321;
bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}
int main() {

    queue<pair<pair<int, int>, pair<int, int>>> move;
    //ff=x, fs=y, sf = step, ss=break wall
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            map[i][j] = (int)s[j] - 48;
        }
    }

    move.push({ {0,0},{1,0} });
    visit[0][0][0] = true;
    while (!move.empty()) {
        int x = move.front().first.first;
        int y = move.front().first.second;
        int step = move.front().second.first;
        int brk = move.front().second.second;

        move.pop();
        if (x == n - 1 && y == m - 1) {
            ans = min(ans, step);
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!OOB(nx, ny) && map[nx][ny] == 0 && visit[nx][ny][brk] == false) {
                move.push({ { nx,ny }, { step + 1,brk } });

                visit[nx][ny][brk] = true;
            }
            if (!OOB(nx, ny) && map[nx][ny] == 1 && brk < k && visit[nx][ny][brk] == false) {
                move.push({ { nx,ny }, { step + 1,brk + 1 } });

                visit[nx][ny][brk + 1] = true;
            }

        }
    }
    if (ans == 987654321) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}

//운 좋게 솔브한 문제. 기존의 1번 문제에서 K로 배열을 늘려준 것 밖에 없다. 